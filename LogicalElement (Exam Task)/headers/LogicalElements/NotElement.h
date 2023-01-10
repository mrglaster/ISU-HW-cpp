#ifndef NOTELEMENT_H_INCLUDED
#define NOTELEMENT_H_INCLUDED

#include <vector>
#include "LogicalElement.h"

class NotElement : public LogicalElement{

    public:

        /**Empty constructor*/
        NotElement(int _id){
            checkRegularId(_id);
            elementValues = {false};
            updateElement();
        }

        /**Constructor by value*/
        NotElement(int _id, bool value){
            checkRegularId(_id);
            elementValues = {value};
            updateElement();
        }

        /**Constructor by vector*/
        NotElement(int _id, std::vector<int> value){
            checkRegularId(_id);
            if(value.size() != 1) {
                throw  std::invalid_argument( "Unexpected input: required vector of size 1" );
            }
            elementValues = {value[0]};
            updateElement();
        }


        /**Element update override*/
        void updateElement() override{
            elementValues[1] = !elementValues[0];
        }

        /**Returns result*/
        bool getResult() override {
            updateElement();
            return elementValues[1];
        }

        /**What the element is it*/
        std::string whoAmI() override{
            return "NOT";
        }

        /**Set ups element's inputs for concrete output value*/
        void setUpOutputValue(bool value) override{
            if (value) {
                 elementValues[0] = 0;
            } else {
                elementValues[0] = 1;
            }
            updateElement();
        }
};


#endif // NOTELEMENT_H_INCLUDED
