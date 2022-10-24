#include <iostream>
#include <cstdio>
#include <windows.h>

#include "Rational.h"
#include "quadratic_equation.h"
using namespace std;

#pragma execution_character_set( "utf-8" )

int main(){

    SetConsoleOutputCP( 65001 );
    cout<<recurent_root(Rational(1,2), Rational(5,1));

}
