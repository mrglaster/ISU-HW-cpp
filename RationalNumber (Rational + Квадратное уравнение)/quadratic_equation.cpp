#include "quadratic_equation.h"
#include <stdexcept>


const int OUTPUT_EQUATION = 1;

// Reads quadratic equation's parameters: a, b, c
Rational* read_quadratic_equation(){
    Rational* arguments = read_ratios(3);
    if (OUTPUT_EQUATION){
        print_square_eq(arguments);
    }
    check_descriminant(arguments);
    return arguments;
}

// Get Discriminant
Rational get_discriminant(Rational* eq_args){
    return eq_args[1]*eq_args[1] - Rational(4)*eq_args[0]*eq_args[2];
}

//Discriminant check
void check_descriminant(Rational* eq_args){
    if(get_discriminant(eq_args) < Rational(0)){
        cout<<"It's impossible to solve this equation: discriminant is below zero: "<<get_discriminant(eq_args);
    }
}


// Byotiful quadratic equation output
void print_square_eq(Rational* arguments){
    cout<<"Detected square equation: "<<arguments[0]<<" × X² "<<'+'<<" "<<arguments[1]<<" × X "<<'+'<<" "<<arguments[2]<<endl;
}

