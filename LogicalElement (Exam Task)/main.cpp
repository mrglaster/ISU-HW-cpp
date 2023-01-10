#include <iostream>
#include "headers/Demonstration/Demonstration.h"
#include "headers/LogicalScheme/LogicalScheme.h"
#include <random>
#include "headers/TablePrinter/TablePrinter.h"
#include "headers/BinaryProcessor/BinaryProcessor.h"
#include <vector>
using namespace std;




int main(){
    srand(time(NULL));
    demoPrintTruthTable();
    return 0;
}
