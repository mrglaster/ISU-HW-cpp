#ifndef XORELEMENT_H_INCLUDED
#define XORELEMENT_H_INCLUDED

#include <vector>
#include "LogicalElement.h"

/*XOR (exclusive OR, Исключающее Или) gate Class **/
class XorElement : public LogicalElement{

    private:
         bool doXor(int valueOne, int valueTwo){
            return (bool)(valueOne ^ valueTwo);
        }
    public:

        /**Constructor for cases, when input values are known*/
        XorElement(int _id, std::vector<int> _initValues) {
            checkRegularId(_id);
            id = _id;
            elementValues = {_initValues[0], _initValues[1], doXor(_initValues[0], _initValues[1])};
        }

        /**Constructor by 2 values*/
        XorElement(int _id, bool valueOne, bool valueTwo){
            checkRegularId(_id);
            id = _id;
            elementValues = {valueOne, valueTwo, doXor(valueOne, valueTwo)};
        }

        /**Creates `Empty` XorElement, who's input values are 0s*/
        XorElement(int _id){
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
            return "XOR";
        }

        /**Updates Element's output value*/
        void updateElement() override{
            elementValues[2] = doXor(elementValues[0], elementValues[1]);
        }

        /**Set ups element's inputs for concrete output value*/
        void setUpOutputValue(bool value) override{
            if (value) {
                 elementValues[0] = 0;
                 elementValues[1] = 1;
            } else {
                elementValues[0] = 1;
                elementValues[1] = 1;
            }
            updateElement();
        }

};


#endif // XORELEMENT_H_INCLUDED
