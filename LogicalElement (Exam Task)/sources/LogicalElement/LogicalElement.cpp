#include <vector>
#include <string>
#include <stdexcept>
#include "../../headers/LogicalElements/LogicalElement.h"


/**Getter for element's ID*/
int LogicalElement::getId(){
    return id;
}

/**Setter for element's ID*/
void LogicalElement::setId(int _id){
    checkRegularId(_id);
    id = _id;
}

/**Sets value on the element's input and updates result*/
void LogicalElement::setValue(int inputId, bool value){
    if (inputId < 0 || inputId > 1) throw std::invalid_argument( "Unexpected input id: required 0 or 1" );
        elementValues[inputId] = value;
        updateElement();
}

/**Returns maximal possible input id for current element*/
int LogicalElement::getInputsMaxId(){
    return inputsCount - 1;
}

/**Connects other element to this one*/
void LogicalElement::connectToMe(LogicalElement* element, int inputId) {
    if (element->getId() == id) throw std::invalid_argument( "Error! You can't connect an element to itself!" );
    if (inputId > getInputsMaxId())  throw std::invalid_argument( "Unexpected input id!" );
    setValue(inputId, element->getResult());
    element->isConnected = true;
    element->connectionsIds.push_back(id);
    gotConnection = true;
    updateElement();
}

/**Is current element the result element (other elements are connected to this one, but this one isn't connected to other)*/
bool LogicalElement::isResultElement(){
    return !isConnected && gotConnection;
}

/**Is current element an input element (is connected to other elements, but no one element is connected to this one)*/
bool LogicalElement::isInputElement(){
    return isConnected && !gotConnection;
}

/**Validates ID for default constructor*/
void LogicalElement::checkRegularId(int id){
    if (id < 0) throw std::invalid_argument( "ID should be greater than 0 and amount of inputs must me equal of 2" );
}

/**Checks if input vector is valid for 2-inputs elements*/
void LogicalElement::checkInputLength(std::vector<int> _initValues){
    if (_initValues.size() != 2)  throw std::invalid_argument( "Unexpected input: 2 elements vector required!" );
}

/**Sets random values on element's inputs*/
void LogicalElement::randomify(){
    for (int i = 0; i < elementValues.size(); i++){
        elementValues[i] = rand()%2;
    }
    updateElement();
}
