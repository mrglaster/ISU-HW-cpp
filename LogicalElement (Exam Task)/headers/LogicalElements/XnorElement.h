#ifndef XNORELEMENT_H_INCLUDED
#define XNORELEMENT_H_INCLUDED


#include "LogicalElement.h"
#include <vector>

/**XNOR (exclusive-NOR, логическое дополнение шлюза Исключающее ИЛИ) Gate Class*/
class XnorElement : public LogicalElement {
    private:
         bool doXnor(int valueOne, int valueTwo){
            return !((bool)(valueOne ^ valueTwo));
        }

    public:
        /**Constructor for cases, when input values are known*/
        XnorElement(int _id, std::vector<int> _initValues) {
            checkRegularId(_id);
            id = _id;
            elementValues = {_initValues[0], _initValues[1], doXnor(_initValues[0], _initValues[1])};
        }

        /**Constructor by 2 values*/
        XnorElement(int _id, bool valueOne, bool valueTwo){
            checkRegularId(_id);
            id = _id;
            elementValues = {valueOne, valueTwo, doXnor(valueOne, valueTwo)};
        }

        /**Creates `Empty` XnorElement, who's input values are 0s*/
        XnorElement(int _id){
            if (_id < 0) {
                 throw std::invalid_argument( "Invalid ID: this value must be equal or greater than 0" );
            }
            elementValues = {0, 0, 1};
        }

        /**Returns value on the output of the element*/
        bool getResult() override {
            return elementValues[2];
        }

        /**Returns what the element is it*/
        std::string whoAmI() override {
            return "XNOR";
        }

        /**Updates Element's output value*/
        void updateElement() override{
            elementValues[2] = doXnor(elementValues[0], elementValues[1]);
        }

        /**Set ups element's inputs for concrete output value*/
        void setUpOutputValue(bool value) override{
            if (value) {
                 elementValues[0] = 0;
                 elementValues[1] = 0;
            } else {
                elementValues[0] = 1;
                elementValues[1] = 0;
            }
            updateElement();
        }

};



#endif // XNORELEMENT_H_INCLUDED
