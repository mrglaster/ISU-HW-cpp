#ifndef QUADRATIC_EQUATION_H_INCLUDED
#define QUADRATIC_EQUATION_H_INCLUDED

#include "Rational.h"
extern const int OUTPUT_EQUATION;

//Read quadratic equation
Rational* read_quadratic_equation();

//Discriminant calculation
Rational get_discriminant(Rational* eq_args);


//Print square eq
void print_square_eq(Rational* arguments);


//Descriminant check
void check_descriminant(Rational* eq_args);

#endif
