#ifndef NANDELEMENT_H_INCLUDED
#define NANDELEMENT_H_INCLUDED


#include <vector>
#include "LogicalElement.h"

/**NAND (not and, Штрих Шеффера) class*/
class NandElement : public LogicalElement{

    private:

        bool doNand(int valueOne, int valueTwo){
            return !(valueOne && valueTwo);
        }
    public:
        /**Constructor for cases, when input values are known*/
        NandElement(int _id, std::vector<int> _initValues) {
            checkRegularId(_id);
            id = _id;
            elementValues = {_initValues[0], _initValues[1], doNand(_initValues[0], _initValues[1]) };
        }

        /**Constructor by 2 values*/
        NandElement(int _id, bool valueOne, bool valueTwo){
            checkRegularId(_id);
            id = _id;
            elementValues = {valueOne, valueTwo, doNand(valueOne, valueTwo)};
        }

        /**Creates `Empty` NandElement, who's input values are 0s*/
        NandElement(int _id){
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
            return "NAND";
        }

        /**Updates Element's output value*/
        void updateElement() override{
            elementValues[2] = doNand(elementValues[0], elementValues[1]);
        }


};

#endif // NANDELEMENT_H_INCLUDED
