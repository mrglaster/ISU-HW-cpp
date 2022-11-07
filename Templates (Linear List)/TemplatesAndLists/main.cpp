#include <iostream>
#include "LineList.h"
using namespace std;

/**

    The  Josephus Problem

A number of people are standing in a circle waiting to be executed.
Counting begins at a specified point in the circle and proceeds around the circle
in a specified direction.
After a specified number of people are skipped, the next person is executed.
The procedure is repeated with the remaining people, starting with the next person,
going in the same direction and skipping the same number of people,
until only one person remains, and is freed.

*/



/** Array containing all players */
LinearList<int> players_list;

/** Initializes the array of players */
void build_list(int length){
   players_list.insertFirst(1);
   LinearListElement<int>* ptr = players_list.getStart();
   for(int i = 2; i < length+1; i++){
        players_list.insertAfter(ptr, i);
        ptr = ptr->getNext();
   }
}

/** The Josephus Problem function */
void josephus_problem(int kn){
    int r = 0;
    for(LinearListElement<int>* it = players_list.getStart(); players_list.getStart()->getNext() != 0;){
        r++;
        if(r == kn-1){
            if(it->getNext() == 0) players_list.deleteFirst();
            else players_list.deleteAfter(it);
            r = 0;
        }
        if(it->getNext() == 0) it = players_list.getStart();
        else it = it->getNext();
    }
    cout<<"Survived player is: "<<players_list;
}

/** Checks if inputed data is correct*/
int read_int_checked(){
    int value = 0;
    cin >> value;
    if( value<=0 || cin.fail()){
        cout<<"Wrong input value!"<<endl;
        exit(-1);
    }
    return value;
}

/** Preparations for Problem Solving */
void init_game(){

    //Reading data
    cout<<"How many players will play the game?"<<endl;
    int players = read_int_checked();
    cout<<"Which killing number we'll have?"<<endl;
    int kn = read_int_checked();

    //Initialize array of players
    build_list(players);

    //special case handling
    if(kn == 1 ){
        cout<<"Survived player is: "<<players_list.getLast()->getData();
        exit(0);
    }

    //Solve the Josephus Problem
    josephus_problem(kn);
}


/**Main function*/
int main(){
    init_game();
}
