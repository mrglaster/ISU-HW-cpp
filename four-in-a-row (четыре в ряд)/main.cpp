#include <iostream>
#include "field.h"

using namespace std;

int main()
{
    Field field(true);
    while(!field.isOver()){
        field.print();
        string name;
        if(field.isRedTurnNow()) name="Red";
        else name="Yellow";
        cout<<endl;
        cout<<"Now turn is: "<<name<<endl;
        cout<<"Input the row in u'll add a color"<<endl<<endl;
        int column = 0;
        cin>>column;
        field.makeTurn(column);
    }
    field.printResult();
    return 0;
}
