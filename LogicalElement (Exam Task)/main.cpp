#include <iostream>
#include "headers/Demonstration/Demonstration.h"
#include <random>
#include <vector>
#include <time.h>
using namespace std;




int main(){
    srand(time(NULL));
    demoPrintTruthTable();
    demoRandomInputResultAffect();
    return 0;
}
