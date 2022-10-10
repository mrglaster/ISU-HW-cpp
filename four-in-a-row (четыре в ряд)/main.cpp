#include <iostream>
#include "field.h"
#include "field_consts.h"

using namespace std;

int main()
{
    Field field(true);
    while(!field.isOver()){
        field.print();
        string name;
        if(field.isRedTurnNow()) name=CL_RED;
        else name=CL_YELLOW;
        cout<<endl;
        cout<<TURN_SETTER<<name<<endl;
        cout<<GUIDE_TEXT<<endl<<endl;
        int column = 0;
        cin>>column;
        field.makeTurn(column);
    }
    field.printResult();
    return 0;
}
