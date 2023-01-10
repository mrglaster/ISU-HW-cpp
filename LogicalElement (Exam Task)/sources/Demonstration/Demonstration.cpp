#include <iostream>
#include "../../headers/LogicalElements/BufferElement.h"
#include "../../headers/LogicalElements/AndElement.h"
#include "../../headers/LogicalElements/OrElement.h"
#include "../../headers/LogicalElements/NotElement.h"
#include "../../headers/LogicalElements/NandElement.h"
#include "../../headers/LogicalScheme/LogicalScheme.h"
#include "../../headers/Demonstration/Demonstration.h"

/**Prints list of elements of the scheme*/
void demoShowElements(){
    //Check Scheme1
    AndElement andEla(0, 1, 0);
    OrElement orEla(0, 0, 0);
    NandElement nandEla(0, 0, 0);
    NotElement notEla(0, 0);
    BufferElement bufEla(0, 0);
    LogicalScheme* testScheme = new LogicalScheme();

    //adding elements
    testScheme->addElement(andEla);
    testScheme->addElement(orEla);
    testScheme->addElement(nandEla);
    testScheme->addElement(notEla);
    testScheme->addElement(bufEla);
    testScheme->printElements();
    delete testScheme;
}

/**Finds result values for hand-input scheme*/
void demoHandsInput(){

    //Check Scheme 1
    AndElement andEla(0, 1, 0);
    OrElement orEla(0, 0, 0);
    NandElement nandEla(0, 0, 0);
    NotElement notEla(0, 0);
    BufferElement bufEla(0, 0);
    LogicalScheme* testScheme = new LogicalScheme();

    //adding elements
    testScheme->addElement(andEla);
    testScheme->addElement(orEla);
    testScheme->addElement(nandEla);
    testScheme->addElement(notEla);
    testScheme->addElement(bufEla);


    //adding connections
    testScheme->addConnection(0, 2, 0);
    testScheme->addConnection(1, 2, 1);
    testScheme->addConnection(2, 3, 0);
    testScheme->addConnection(2, 4, 0);
    testScheme->printSchemeResults();
    delete testScheme;
}

/**Scheme input via file*/
void demoFileInput(){
    LogicalScheme* testScheme = new LogicalScheme("example_schemes/scheme_1/scheme1.txt");
    testScheme->printSchemeResults();
    delete testScheme;
}
/**Demonstration of program abortion on attempt to create the loop*/
void demoLoopErrorCheck(){
    LogicalScheme* testScheme = new LogicalScheme("example_schemes/scheme_2_error/scheme2Loop.txt");
    testScheme->printSchemeResults();
    delete testScheme;
}

/**Generation of truth table for file-loaded scheme*/
void demoTruthTableGen(){
}

/**Demonstrates generation of random values on element's inputs*/
void demoRandomInputs(){
    LogicalScheme* testScheme = new LogicalScheme("example_schemes/scheme_1/scheme1.txt");
    testScheme->generateRandomInputs(true);
    delete testScheme;
}


void demoRandomInputResultAffect(){
    LogicalScheme* testScheme = new LogicalScheme("example_schemes/scheme_3/scheme3.txt");
    testScheme->printElements();
    testScheme->printSchemeResults();
    testScheme->generateRandomInputs(true);
    testScheme->printSchemeResults();

}
