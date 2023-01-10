#ifndef LOGICALELEMENT_H_INCLUDED
#define LOGICALELEMENT_H_INCLUDED

#include <vector>
#include <string>



/**General abstract LogicalElement class*/
class LogicalElement{

    protected:
        /**Class parameters*/
        int id = 0;
        int inputsCount = 2;
        bool isConnected = false;
        bool gotConnection = false;

        std::vector<int> connectionsIds;
        std::vector<bool> elementValues;

    public:
        /**Virtual functions for LogicalElements*/
        virtual bool getResult() = 0;
        virtual std::string whoAmI() = 0;
        virtual void updateElement() = 0;

        /**Required getters and setters*/
        int getId();
        void setId(int _id);

        /**Sets value on the element's input and updates result*/
        void setValue(int inputId, bool value);

        /**Returns Maximal Possible input id*/
        int getInputsMaxId();

        /**Connects other element to current one*/
        void connectToMe(LogicalElement* element, int inputId);

        /**Is current element the result element (other elements are connected to this one, but this one isn't connected to other)*/
        bool isResultElement();

        /**Is current element an input element (is connected to other elements, but no one element is connected to this one)*/
        bool isInputElement();

        /**Validates ID for default constructor*/
        void checkRegularId(int id);

        /**Checks if input vector is valid for 2-inputs elements*/
        void checkInputLength(std::vector<int> _initValues);

        /**Returns connections of current element*/
        std::vector<int> getConnections();

        /**Randomly changes values on element's inputs*/
        void randomify();

};


#endif // LOGICALELEMENT_H_INCLUDED
