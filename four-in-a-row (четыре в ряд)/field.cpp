#include "field.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void Clear_console(){
    system("CLS");
}


void Field::clear(bool isRedFirst){
    isRedTurn = isRedFirst;
    winner = EMPTY;
    for(int i=0; i<FIELD_WIDTH; i++)
        for(int j=0; j<FIELD_HEIGHT; j++){
            cells[i][j]=EMPTY;
        }
}

Field::Field(bool isRedFirst){
    clear(isRedFirst);
}

void Field::checkWinner(){
    for(int i=0; i<FIELD_WIDTH; i++){
        for(int j=0; j<FIELD_HEIGHT; j++){
            Cell start = cells[i][j];
            if(start==EMPTY) continue;
            for(int dir=0; dir<DIR_NUMBER; dir++){
                int length=0, iline = i, jline = j;
                while(++length<WIN_LENGTH){
                    iline+=di[dir];
                    jline+=dj[dir];
                    if(iline<0 || iline>=FIELD_WIDTH || jline<0 || jline>=FIELD_HEIGHT) break;
                    if(cells[iline][jline]!=start) break;
                }
                if(length==WIN_LENGTH){
                    winner = start;
                    return;
                }
            }
        }
    }
}

void Field::print() const{
    Clear_console();
    for(int i=0; i<FIELD_WIDTH; i++){
        cout<<endl;
        for(int j=0; j<FIELD_HEIGHT; j++){
            Cell currentcell = cells[i][j];
            if(currentcell==EMPTY) cout<<"E ";
            else if(currentcell==RED) cout<<"R ";
            else cout<<"Y ";
        }
    }
}


bool Field::isRedTurnNow() const{
    if(isRedTurn) return true;
    return false;
}

bool Field::isOver() const{
    if(winner!=EMPTY) return true;
    for(int i=0;i<FIELD_WIDTH;i++){
        for(int j=0; j<FIELD_HEIGHT; j++){
            if(cells[i][j]==EMPTY) return false;
        }
    }
    return true;
}

bool Field::makeTurn(int column){
    if(winner!=EMPTY || column<1 || column>FIELD_WIDTH) return false;
    int i = column-1;
    for(int j=0; j<FIELD_HEIGHT; j++){
        if(cells[i][j]==EMPTY){
            cells[i][j] = isRedTurn ? RED: YELLOW;
            checkWinner();
            isRedTurn = !isRedTurn;
            return true;
        }
    }
    return false;
}

void Field::printResult() const{
    if(isOver() && winner!=EMPTY){
        print();
        cout<<endl<<endl;
        if(winner==RED) cout<<"RED WON! YAY!"<<endl;
        else cout<<"YELLOW WON! YAY!"<<endl;
    }
}
