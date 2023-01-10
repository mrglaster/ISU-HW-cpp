#ifndef ANDELEMENT_H_INCLUDED
#define ANDELEMENT_H_INCLUDED

#include "LogicalElement.h"
#include <vector>

class AndElement : public LogicalElement {

    public:
        /**Constructor for cases, when input values are known*/
        AndElement(int _id, std::vector<int> _initValues) {
            checkRegularId(_id);
            id = _id;
            elementValues = {_initValues[0], _initValues[1], _initValues[0] && _initValues[1]};
        }

        /**Constructor by 2 values*/
        AndElement(int _id, bool valueOne, bool valueTwo){
            checkRegularId(_id);
            id = _id;
            elementValues = {valueOne, valueTwo, valueOne & valueTwo};
        }

        /**Creates `Empty` AndElement, who's input values are 0s*/
        AndElement(int _id){
            if (_id < 0) {
                 throw std::invalid_argument( "Invalid ID: this value must be equal or greater than 0" );
            }
            elementValues = {0, 0, 0};
        }

        /**Returns value on the output of the element*/
        bool getResult() override {
            return elementValues[2];
        }

        /**Returns what the element is it*/
        std::string whoAmI() override {
            return "AND";
        }

        /**Updates Element's output value*/
        void updateElement() override{
            elementValues[2] = elementValues[0] && elementValues[1];
        }




};



#endif // ANDELEMENT_H_INCLUDED
