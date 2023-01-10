#ifndef NORELEMENT_H_INCLUDED
#define NORELEMENT_H_INCLUDED

#include <vector>
#include "LogicalElement.h"

/**NOR gate (aka pier arrow, стрелка Пирса) class*/
class NorElement : public LogicalElement{

    private:
        bool doNor(int valueOne, int valueTwo){
            return !(valueOne || valueTwo);
        }
    public:

        /**Constructor for cases, when input values are known*/
        NorElement(int _id, std::vector<int> _initValues) {
            checkRegularId(_id);
            id = _id;
            elementValues = {_initValues[0], _initValues[1], doNor(_initValues[0], _initValues[1]) };
        }

        /**Constructor by 2 values*/
        NorElement(int _id, bool valueOne, bool valueTwo){
            checkRegularId(_id);
            id = _id;
            elementValues = {valueOne, valueTwo, doNor(valueOne, valueTwo)};
        }

        /**Creates `Empty` NorElement, who's input values are 0s*/
        NorElement(int _id){
            if (_id < 0) {
                 throw std::invalid_argument( "Invalid ID: this value must be equal or greater than 0" );
            }
            elementValues = {0, 0, 1};
        }

        /**Returns value on the output of the element*/
        bool getResult() override {
            updateElement();
            return elementValues[2];
        }

        /**Returns what the element is it*/
        std::string whoAmI() override {
            return "NOR";
        }

        /**Updates Element's output value*/
        void updateElement() override{
            elementValues[2] = doNor(elementValues[0], elementValues[1]);
        }

        /**Set ups element's inputs for concrete output value*/
        void setUpOutputValue(bool value) override{
            if (value) {
                 elementValues[0] = 0;
                 elementValues[1] = 0;
            } else {
                elementValues[0] = 1;
                elementValues[1] = 1;
            }
            updateElement();
        }
};

#endif // NORELEMENT_H_INCLUDED
