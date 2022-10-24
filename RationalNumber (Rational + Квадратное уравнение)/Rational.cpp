#include <iostream>
#include <stdexcept>
#include <limits.h>
#include "Rational.h"
using namespace std;

const int INPUT_HINT = 1;
int GLOBAL_OVERFLOW_FLAG = 0;

//Default constructor
Rational::Rational(){
    numerator = 0;
    denumerator = 1;
    is_overflowed = 0;
}

//Cast one number into Rational
Rational::Rational(int number){
    numerator = number;
    denumerator = 1;
    is_overflowed = 0;
}


int euqlidus(int a, int b){
    if (a % b == 0) return b;
    return euqlidus(b, a % b);
}


void Rational::simplify(){
    int a = numerator;
    int b = denumerator;
    int nod = euqlidus(a,b);
    numerator = numerator/nod;
    denumerator = denumerator/nod;
    if (denumerator < 0 && numerator > 0 ) {
        denumerator*=-1;
        numerator*=-1;
    }
}

//Make one rational from 2 ints
Rational::Rational(int numerator_custom, int denumerator_custom){
    numerator = numerator_custom;
    is_overflowed = 0;
    if(denumerator_custom!=0) denumerator = denumerator_custom;
    else{
        cout<<"("<<numerator<<";"<<denumerator<<")"<<endl;
        cout<<"Error: Anavailable denumerator! Expected: int !=0"<<endl;
        exit(-1);
    }
    if(denumerator<0 && numerator<0){
        numerator*=(-1);
        denumerator*=(-1);
    }

    simplify();
}

//Overload of output operator
ostream& operator<<(ostream& out, const Rational& r){
    if(r.numerator==0) out<<"0";
    else if (r.denumerator==0) out<<"Infinity!";
    else if(r.denumerator==r.numerator) out<<"1";
    else if(r.denumerator==1) out<<r.numerator;
    else out<<r.numerator<<"\\"<<r.denumerator;
    return out;
}

//Overload of input operator
istream& operator>>(istream& is,  Rational& r){
    if(INPUT_HINT) cout<<"Input numerator and after denumerator"<<endl;
    is>>r.numerator>>r.denumerator;
    return is;
}

//Overload of adding operator
Rational& Rational::operator+=(const Rational& r){
    numerator = (numerator*r.denumerator+denumerator*r.numerator);
    denumerator*=r.denumerator;
    simplify();
    return *this;
}

//Overload of + operator
Rational Rational::operator +(const Rational &r) const {
   Rational res(*this);
   return res += r;
}

//Overload of - operator. "Classical" minus
Rational Rational::operator-(const Rational &r) const{
    Rational res(*this);
    Rational r1(-1*r.numerator, r.denumerator);
    res+=r1;
    return res;


}

//Unar minus
Rational Rational::operator -() const{
   Rational r(-numerator, denumerator);
   return r;
}

//Overload of decrease operator
Rational& Rational::operator -=(const Rational& r) {
    return (*this += (-r));
}

//Overload of multiply operator
Rational Rational::operator*(const Rational &r) const{
    if( numerator > INT_MAX/r.numerator || denumerator > INT_MAX/r.denumerator){
        GLOBAL_OVERFLOW_FLAG = 1;
        return *this;
    }
    return Rational(numerator*r.numerator, denumerator*r.denumerator);
}

//Overload of divide operator
Rational Rational::operator/(const Rational& r) const{
    Rational result = Rational(numerator, denumerator)*Rational(r.denumerator, r.numerator);
    return result;
}

//Overload of prefix increment operator
Rational& Rational::operator ++(){
   numerator += denumerator;
   return *this;
}

//Overload of postfix increment operator
Rational Rational::operator ++(int) {
    Rational r(*this);
    numerator += denumerator;
    return r;
}

//Overload of operator "Is equal"
bool Rational::operator ==(const Rational& r) const{
    return (numerator==r.numerator) && (denumerator==r.denumerator);
}

//Overload of operator "Is not equal"
bool Rational::operator !=(const Rational& r) const{
    return !(*this==r);
}

// Overload of operator "less than"
bool Rational::operator <(const Rational& r) const{
    if (denumerator == r.denumerator ) return numerator<r.numerator;
    return numerator*r.denumerator<r.numerator*denumerator;
}

//Overload of operator "more than
bool Rational:: operator >(const Rational& r) const{
    return !(*this<r);
}

// Overload of operator "less or equal"
bool Rational::operator <=(const Rational& r) const{
    return *this<r || *this==r;
}

// Overload of operator "more or equal"
bool Rational::operator >=(const Rational& r) const{
    return *this>r || *this==r;
}

//Cast rational to int
Rational::operator int() const{
    return numerator/denumerator;
}

//Cast rational to double
Rational::operator double() const{
    return (double)numerator/denumerator;
}

// Read n ratios
Rational* read_ratios(int n){
    if(n <= 0){
        throw std::invalid_argument( "Excepted natural number!");
    }
    cout<<"There are "<<n<<" ratios to read from keyboard"<<endl<<endl;
    Rational* ratios = new Rational[n];
    int current_position = 0;
    for (int i=0; i < n; i++) {
        cin>>ratios[current_position];
        current_position++;
    }
    return ratios;
}

// Basic functions test
void basic_functions_test(){
    Rational* numbers = read_ratios(2);
    Rational ratio_1 = numbers[0];
    Rational ratio_2 = numbers[1];
    cout<<ratio_1<<" + "<<ratio_2<<" = "<<ratio_1+ratio_2<<endl;
    cout<<ratio_1<<" - "<<ratio_2<<" = "<<ratio_1-ratio_2<<endl;
    cout<<ratio_1<<" * "<<ratio_2<<" = "<<ratio_1*ratio_2<<endl;
    cout<<ratio_1<<" / "<<ratio_2<<" = "<<ratio_1/ratio_2<<endl;

}

// Rational number multiplying with overflow check
Rational mul_safe(Rational first, Rational second){
    if(first.numerator > INT_MAX/second.numerator || first.denumerator > INT_MAX/second.denumerator) {
        first.is_overflowed = 1;
        return first;
    }
    return Rational(first.numerator*second.numerator, first.denumerator*second.denumerator);
}

Rational add_safe(Rational first, Rational second){
    if(first.numerator > INT_MAX - second.denumerator) {first.is_overflowed = 1; return first;}
    return first+second;

}

//Recurent root of rational number
Rational recurent_root(Rational number, Rational a){
    cout<<"Processing rational: "<<number<<endl;
    if (number.numerator == 0 && number.denumerator != 0) return Rational(0);
    if (number.denumerator == 0 ) {
        cout<<"Unable to solve the task, got divide by zero! Potential answer: ∞ (Infinity)"<<endl;
    }
    Rational first_step = a/number;
    if (!GLOBAL_OVERFLOW_FLAG){
        first_step+=number;
        if(!GLOBAL_OVERFLOW_FLAG){
            first_step = first_step * Rational(1,2);
            if(!GLOBAL_OVERFLOW_FLAG){
                if(first_step * first_step < number) return number;
                return recurent_root(first_step, a);
            }
            return number;
        }
        return number;
    }
    return number;
}
