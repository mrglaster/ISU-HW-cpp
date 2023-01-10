#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

#include "../../headers/LogicalScheme/LogicalScheme.h"
#include "../../headers/LogicalElements/LogicalElement.h"
#include "../../headers/LogicalElements/AndElement.h"
#include "../../headers/LogicalElements/BufferElement.h"
#include "../../headers/LogicalElements/OrElement.h"
#include "../../headers/LogicalElements/NandElement.h"
#include "../../headers/LogicalElements/NorElement.h"
#include "../../headers/LogicalElements/NotElement.h"
#include "../../headers/LogicalElements/XnorElement.h"
#include "../../headers/LogicalElements/XorElement.h"

#include "../../headers/TablePrinter/TablePrinter.h"
#include "../../headers/ConnectionsGraph/ConnectionsGraph.h"
#include "../../headers/BinaryProcessor/BinaryProcessor.h"

ConnectionsGraph cons(100);

/**Empty constructor*/
LogicalScheme::LogicalScheme(){
}


/**Read the scheme from file*/
LogicalScheme::LogicalScheme(char* filename) {
    ifstream infile(filename);
    if (infile.fail()) {
        throw invalid_argument("File " + (string)filename+ " Not Found!");
    }


    std::map <std::string, int> actionsMap = {
        {"CON", CON},
        {"AND", AND},
        {"OR", OR},
        {"NOT", NOT},
        {"XOR", XOR},
        {"NAND", NAND},
        {"NOR", NOR},
        {"XNOR", XNOR},
        {"BUF", BUF}
    };

    string line;
    int currentLine = 0;

    while (getline(infile, line)){

        //Reading action's name
        stringstream iss(line);
        string actionName;
        int ifVal = -1;
        int isVal = -1;
        iss >> actionName;


        //Checks the action's name
        if (actionsMap.find(actionName) == actionsMap.end()){
                throw std::invalid_argument("Got Unknown Action: "+actionName);
        }

        currentLine++;
        LogicalElement* elem;
        switch (actionsMap[actionName]){
            case CON: {
                int source, destination, inputId;
                iss >> source >> destination >> inputId;
                if (iss.fail()) throw std::invalid_argument("Some error occurred during parameters reading on line: " + std::to_string(currentLine));
                if (source == destination) throw std::invalid_argument("Error on line " + std::to_string(currentLine) + " : Attempt to create the loop");
                if (inputId > schemeElements[destination]->getInputsMaxId() || inputId < 0) throw std::invalid_argument("Error on line " + std::to_string(currentLine) + " : Wrong Connection Pin Id: " + std::to_string(inputId));
                if (!cons.areConnected(destination, source)) {
                    addConnection(source, destination, inputId);
                    cons.addEdge(source, destination);
                    updateConnections();
                } else {
                    throw std::invalid_argument("Error on line " + std::to_string(currentLine) + " : Attempt to create the loop!");
                }
                break;
            }

            case AND: {
                iss >> ifVal >> isVal;
               if (iss.fail()) throw std::invalid_argument("Some error occurred during parameters reading on line: " + std::to_string(currentLine));
                elem = new AndElement(0, ifVal, isVal);
                addElement(*elem);
                break;
            }

            case OR: {
                iss >> ifVal >> isVal;
                if (iss.fail()) throw std::invalid_argument("Some error occurred during parameters reading on line: " + std::to_string(currentLine));
                elem = new OrElement(0, ifVal, isVal);
                addElement(*elem);
                break;
            }

            case NOT: {
                iss >> ifVal;
                if (iss.fail()) throw std::invalid_argument("Some error occurred during parameters reading on line: " + std::to_string(currentLine));
                elem = new NotElement(0, ifVal);
                addElement(*elem);
                break;
            }

            case XOR: {
                iss >> ifVal >> isVal;
                if (iss.fail()) throw std::invalid_argument("Some error occurred during parameters reading on line: " + std::to_string(currentLine));
                elem = new XorElement(0, ifVal, isVal);
                addElement(*elem);
                break;
            }

            case NAND:{
                iss >> ifVal >> isVal;
                if (iss.fail()) throw std::invalid_argument("Some error occurred during parameters reading on line: " + std::to_string(currentLine));
                elem = new NandElement(0, ifVal, isVal);
                addElement(*elem);
                break;
            }

            case NOR:{
                iss >> ifVal >> isVal;
                if (iss.fail()) throw std::invalid_argument("Some error occurred during parameters reading on line: " + std::to_string(currentLine));
                elem = new NorElement(0, ifVal, isVal);
                addElement(*elem);
                break;
            }

            case XNOR:{
                iss >> ifVal >> isVal;
                if (iss.fail()) throw std::invalid_argument("Some error occurred during parameters reading on line: " + std::to_string(currentLine));
                elem = new XnorElement(0, ifVal, isVal);
                addElement(*elem);
                break;
            }

            case BUF:{
                iss >> ifVal;
                if (iss.fail()) throw std::invalid_argument("Some error occurred during parameters reading on line: " + std::to_string(currentLine));
                elem = new BufferElement(0, ifVal);
                addElement(*elem);
                break;
            }
        }

        if (actionName != "CON"  && ( (ifVal < 0 || ifVal > 1) || (actionName != "NOT" && actionName != "BUF" && (isVal < 0 || isVal > 1))))  throw std::invalid_argument("Expected value in range [0;1]. Error in line: " + std::to_string(currentLine));

    }
}


/**Destructor*/
LogicalScheme::~LogicalScheme(){
    schemeElements.clear();
}

/**Returns amount of elements in the scheme*/
int LogicalScheme::getElementsAmount(){
    return schemeElements.size();
}

/**Returns vector of elements from the scheme*/
std::vector<LogicalElement*> LogicalScheme::getElements(){
    return schemeElements;
}

/**Is the id of the element, on which we process operation, valid?*/
bool LogicalScheme::isValidId(int id){
    return id >= 0 && id <= getElementsAmount() - 1;
}

/**Returns id for new element of the scheme*/
int LogicalScheme::getNewId(){
    return getElementsAmount();
}

/**Adds the new element to the scheme*/
void LogicalScheme::addElement(LogicalElement& element){
    element.setId(getNewId());
    schemeElements.push_back(&element);
}

/**Adds the new connection to the scheme*/
void LogicalScheme::addConnection(int sourceElemId, int destinationElemId, int destinationInputId){
    if (isValidId(sourceElemId) && isValidId(destinationElemId)) {
        if (destinationInputId <= schemeElements[destinationElemId]->getInputsMaxId() && destinationInputId >=0){
            if (!cons.areConnected(destinationElemId, sourceElemId)){
                    schemeElements[destinationElemId]->connectToMe(schemeElements[sourceElemId], destinationInputId);
                    resetElements();
            }
            else throw std::invalid_argument("Error! Attempt to create the loop!");

        }
    }
}

/**Prints the list of all elements of the scheme*/
void LogicalScheme::printElements(){
    if (getElementsAmount() == 0) std::cout<<"Elements not found!"<<std::endl;
    else {
        TablePrinter ct("Current List of Elements", getElementsAmount(),2);
        ct.setColumnHeader(0, "Element type")
          .setColumnHeader(1, "Output value");
        for(int i = 0; i < getElementsAmount(); i++){
            ct.printValue(schemeElements[i]->whoAmI())
              .printValue(schemeElements[i]->getResult());
        }
    }
}

/**Returns ids of output elements*/
vector<int> LogicalScheme::getOutputElemIds(){
    vector<int> resultsIds;
    for (int i = 0; i < schemeElements.size(); i++){
        if (schemeElements[i]->isResultElement()){
             resultsIds.push_back(i);
        }
    }
    return resultsIds;
}


/**Prints result values for current scheme*/
void LogicalScheme::printSchemeResults(){
    if(schemeElements.size() == 0 ) {
        std::cout<<"Scheme is empty! Can't get result!"<< std::endl;
        exit(0);
    }
    bool hasResultElement = false;
    std::vector<int> succIds;
    int i;
    for (i = 0; i < schemeElements.size(); i++){
        if (schemeElements[i]->isResultElement()){
             succIds.push_back(schemeElements[i]->getId());
             hasResultElement = true;
        }
    }

    if (!hasResultElement) {
        std::cout<<"It seems, the scheme contains UNCONNECTED ELEMENTS! We cant give the result in this case!"<<std::endl;
    } else {

        TablePrinter ct("Scheme Results Values", succIds.size(), 3);
            ct.setColumnHeader(0, "Element ID")
              .setColumnHeader(1, "Element Type")
              .setColumnHeader(2, "Result Value");
        for (i = 0; i < succIds.size(); i++){
            ct.printValue(schemeElements[succIds[i]]->getId())
              .printValue(schemeElements[succIds[i]]->whoAmI())
              .printValue(schemeElements[succIds[i]]->getResult());
        }

    }
}

/**On update scheme values on connection modification*/
void LogicalScheme::updateConnections(){
    if (schemeElements.size()) {
        for (int i = 0; i < schemeElements.size(); i++){
            schemeElements[i]->updateElement();
        }
    }
     resetElements();
}

/**Generates random values on inputElements inputs*/
void LogicalScheme::generateRandomInputs(bool logToConsole){
    if (schemeElements.size() == 0) throw std::invalid_argument("Unable to generate random input values for the empty scheme!");
    vector<int> inputIds = getInputElemIds();
    int i;
    if (inputIds.size() == 0) throw std::invalid_argument("Something went wrong during input elements finding!");
    TablePrinter ct("Input elements random output changes", inputIds.size(), 3);
    if (logToConsole){
        ct.setColumnHeader(0, "Element Type")
          .setColumnHeader(1, "Previous Value")
          .setColumnHeader(2, "New value");
    }
    for (i=0; i < inputIds.size(); i++){
            if (logToConsole){
                ct.printValue(schemeElements[i]->whoAmI())
                  .printValue(schemeElements[i]->getResult());
            }
            schemeElements[i]->randomify();
            resetElements();
            if (logToConsole) ct.printValue(schemeElements[i]->getResult());

    }

}

/**Returns ids of all input elements*/
vector<int> LogicalScheme::getInputElemIds(){
    if (!schemeElements.size()) throw std::invalid_argument("Unable to get elements from the empty scheme");
    vector<int> ids;
    for (int i = 0; i < getElementsAmount(); i++){
        if (schemeElements[i]->isInputElement()) ids.push_back(i);
    }
    return ids;
}


/**Prints only input elements and their conditions*/
void LogicalScheme::printInputElements(){
    vector<int> elems = getInputElemIds();
    if (!elems.size()) cout<<"No input elements found!"<<endl;
    else {
        TablePrinter ct("Input Elements", elems.size(), 3);
        ct.setColumnHeader(0, "Element Id")
          .setColumnHeader(1, "Element Type")
          .setColumnHeader(2, "Output Condition");
        for (int i = 0; i < elems.size(); i++){
            ct.printValue(schemeElements[elems[i]]->getId());
            ct.printValue(schemeElements[elems[i]]->whoAmI());
            ct.printValue(schemeElements[elems[i]]->getResult());
        }

    }
}


/**Scheme's truth table generation*/
void LogicalScheme::printTruthTable(){
    vector<int> elems = getInputElemIds();
    vector<int> outs = getOutputElemIds();
    if (!outs.size()) throw std::invalid_argument("Can't create truth table for non-outputs scheme!");
    int currentLength = elems.size();
    int i;

    if (!currentLength) cout<<"Unable to Create Truth table for empty/non-inputs scheme!"<<endl;
    else {
        int maxBin = binIntToDec(findMaxBinary(currentLength));
        vector<vector<int>> combinations = getBinariesTo(maxBin);
        if (!combinations.size()) cout<<"Something went wrong during truth table building..."<<endl;
        else {
                TablePrinter tp("Scheme truth table", combinations.size(), currentLength + 1);
                for (i = 0; i < currentLength; i++){
                    tp.setColumnHeader(i, schemeElements[elems[i]]->whoAmI()+"_"+std::to_string(schemeElements[elems[i]]->getId()));
                }
                tp.setColumnHeader(currentLength, "Result");
                for (i = 0; i < combinations.size(); i++){
                    vector<int> currentValues = combinations[i];
                    if (currentValues.size() != currentLength) throw std::invalid_argument("Something went wrong during truth table building...");
                    for (int j = 0; j < currentValues.size(); j++){
                        schemeElements[elems[j]]->setUpOutputValue((bool)currentValues[j]);
                        resetElements();
                        tp.printValue(currentValues[j]);
                    }

                    string resultValue = "";
                    for (int j = 0; j < outs.size(); j++){
                        resultValue+= std::to_string(schemeElements[outs[j]]->getResult());
                        resultValue+=" ";

                    }
                   tp.printValue(resultValue);
                }
        }
    }
}

/**Updates elements after modifications*/
void LogicalScheme::resetElements(){
    for (int i = 0 ; i <schemeElements.size(); i++){
         vector<int> elementsToUpdate = schemeElements[i]->getConnections();
         for (int elementId = 0; elementId < elementsToUpdate.size(); elementId++){
                schemeElements[elementsToUpdate[elementId]]->setValue(schemeElements[i]->getResult(), schemeElements[elementsToUpdate[elementId]]->getPinHistoryMap()[i]);
        }
    }
}
