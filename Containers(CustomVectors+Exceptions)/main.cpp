#include <iostream>
#include <chrono>
#include "CustomVector.h"
using namespace std;

/*
        Josephus Problem

A number of people are standing in a circle waiting to be executed.
Counting begins at a specified point in the circle and proceeds around the circle in a specified direction.
After a specified number of people are skipped, the next person is executed.
The procedure is repeated with the remaining people, starting with the next person, going in the same direction and skipping the same number of people,
until only one person remains, and is freed.

*/
int players = 0;
int nkill = 0;
int globnum = 0;

//Get basic values
void get_startvalues(){
    cout<<"How many players will play the game?"<<endl;
    cin>>players;
    cout<<"Every Nth player will be killed. Which N we'll use?"<<endl;
    cin>>nkill;
}


void josephus_problem(CustomVector cv){
        globnum = cv.getSize();
        auto start_time = std::chrono::high_resolution_clock::now();
        int counter = 1;
        while(cv.getSize()!=1){
            counter+= nkill - 1;
            counter%=cv.getSize();
            cv.remove(counter);
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        int dude_left = cv[0]-1;
        if(dude_left==0) dude_left = globnum;
        cout<<"Dude left: "<<dude_left<<endl;
        printf("Shooting took %f mikroseconds\n", (double)(std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count()) );

}

int main()
{
    get_startvalues();
    CustomVector cv = generate_natural_vector(players);
    josephus_problem(cv);
}
