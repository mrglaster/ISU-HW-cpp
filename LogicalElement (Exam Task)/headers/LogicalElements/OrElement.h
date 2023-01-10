#ifndef ORELEMENT_H_INCLUDED
#define ORELEMENT_H_INCLUDED

#include <vector>
#include "LogicalElement.h"

class OrElement : public LogicalElement{

     public:

        /**Constructor by vector*/
        OrElement(int _id,  std::vector<int> _initValues){
            checkRegularId(_id);
            checkInputLength(_initValues);
            id = _id;
            elementValues = {_initValues[0], _initValues[1], _initValues[0] || _initValues[1]};
        }

        /**Constructor by 2 values*/
        OrElement(int _id, bool valueOne, bool valueTwo){
            checkRegularId(_id);
            id = _id;
            elementValues = {valueOne, valueTwo, valueOne || valueTwo};
        }

        /**Simple empty element constructor*/
        OrElement(int _id){
            checkRegularId(_id);
            elementValues = {false, false, false};
        }

        /**Updates Element's output value*/
        void updateElement() override {
            elementValues[2] = elementValues[0] || elementValues[1];
        }

        /**Updates value on the element's output*/
        bool getResult() override {
            updateElement();
            return elementValues[2];
        }

        std::string whoAmI() override{
            return "OR";
        }
};


#endif // ORELEMENT_H_INCLUDED
