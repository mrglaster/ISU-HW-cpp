#ifndef LOGICALSCHEME_H_INCLUDED
#define LOGICALSCHEME_H_INCLUDED

#include <vector>
#include <map>
#include <sstream>
#include "../LogicalElements/LogicalElement.h"


/**Logical Scheme class realisation*/
class LogicalScheme{
    private:
        bool areElementsConnected(int startId, int endId);
        std::vector<LogicalElement*>schemeElements;

    public:

        LogicalScheme(char* filename);
        LogicalScheme();
        ~LogicalScheme();

        bool isValidId(int id);
        int getElementsAmount();
        int getNewId();

        std::vector<LogicalElement*> getElements();
        std::vector<int> getInputElemIds();
        std::vector<int> getOutputElemIds();

        void updateConnections();
        void addElement(LogicalElement &element);
        void addConnection(int sourceElemId, int destinationElemId, int destinationInputId);
        void generateRandomInputs(bool logToConsole);

        void printSchemeResults();
        void printElements();
        void printInputElements();
        void printTruthTable();

        void resetElements();

};


enum{
    CON = 0,
    AND,
    OR,
    NOT,
    XOR,
    NAND,
    NOR,
    XNOR,
    BUF,
};




#endif // LOGICALSCHEME_H_INCLUDED
