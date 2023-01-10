#ifndef BUFFERELEMENT_H_INCLUDED
#define BUFFERELEMENT_H_INCLUDED


#include <vector>
#include "LogicalElement.h"


class BufferElement : public LogicalElement{

    public:
        /**Empty constructor*/
        BufferElement(int _id){
            inputsCount = 1;
            checkRegularId(_id);
            elementValues = {false};
            updateElement();
        }

        /**Constructor by value*/
        BufferElement(int _id, bool value){
            checkRegularId(_id);
            elementValues = {value};
            updateElement();
        }

        /**Constructor by vector*/
        BufferElement(int _id, std::vector<int> value){
            inputsCount = 1;
            checkRegularId(_id);
            if(value.size() != 1) {
                throw  std::invalid_argument( "Unexpected input: required vector of size 1" );
            }
            elementValues = {value[0]};
            updateElement();
        }


        /**Element update override*/
        void updateElement() override{
            elementValues[1] = elementValues[0];
        }

        /**Returns result*/
        bool getResult() override {
            updateElement();
            return elementValues[1];
        }

        /**What the element is it*/
        std::string whoAmI() override{
            return "BUFFER";
        }
};


#endif // BUFFERELEMENT_H_INCLUDED
