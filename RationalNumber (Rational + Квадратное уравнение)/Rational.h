#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED
#include <iostream>
using namespace std;
extern const int INPUT_HINT;
extern const int MAX_APPROXIMATION;

class Rational{
    void simplify();
    public:
        //Class variables
        int numerator;
        int denumerator;
        int is_overflowed;

        //Constructors
        Rational();
        Rational(int numerator);
        Rational(int numerator, int denumerator);

        //Operators

        //IO operators
        friend ostream& operator<<(ostream& os, const Rational& r);
        friend istream& operator>>(istream& is, Rational& r);

        //Math operators
        Rational& operator +=(const Rational& r);
        Rational operator +(const Rational& r) const;
        Rational& operator -=(const Rational& r);
        Rational operator -() const;
        Rational operator-(const Rational& r) const;
        Rational operator*(const Rational& r) const;
        Rational operator/(const Rational& r) const;
        Rational& operator ++();
        Rational operator ++(int);

        //Comparation operators
        bool operator ==(const Rational& r) const;
        bool operator !=(const Rational& r) const;
        bool operator<(const Rational &r) const;
        bool operator<=(const Rational &r) const;
        bool operator>=(const Rational &r) const;
        bool operator>(const Rational &r) const;

        //Type transform operators
        operator int() const;
        operator double() const;


};

Rational* read_ratios(int n);
Rational recurent_root(Rational number, Rational src);
Rational mul_safe(Rational first, Rational second);
void basic_functions_test();


#endif
