#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

#include "../../headers/LogicalScheme/LogicalScheme.h"
#include "../../headers/LogicalElements/LogicalElement.h"


#include "../../headers/TablePrinter/TablePrinter.h"
#include "../../headers/ConnectionsGraph/ConnectionsGraph.h"
#include "../../headers/BinaryProcessor/BinaryProcessor.h"


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
            if (!cons->areConnected(destinationElemId, sourceElemId)){
                    schemeElements[destinationElemId]->connectToMe(schemeElements[sourceElemId], destinationInputId);
                    resetElements();
            }
            else throw std::invalid_argument("Error! Attempt to create the loop!");

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



/**Updates elements after modifications*/
void LogicalScheme::resetElements(){
    for (int i = 0 ; i <schemeElements.size(); i++){
         vector<int> elementsToUpdate = schemeElements[i]->getConnections();
         for (int elementId = 0; elementId < elementsToUpdate.size(); elementId++){
                schemeElements[elementsToUpdate[elementId]]->setValue(schemeElements[i]->getResult(), schemeElements[elementsToUpdate[elementId]]->getPinHistoryMap()[i]);
        }
    }
}
