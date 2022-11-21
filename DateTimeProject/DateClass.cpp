#include "DateClass.h"
#include "TimeClass.h"
#include <iostream>
using namespace std;


char* DAYS_OF_WEEK[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


/**Date constructor*/
Date::Date(int yr, int mth, int d, Time tm){
    year = yr;
    month = mth;
    day = d;
    time = tm;
}

Date::Date(){
    year = 1900;
    month = 1;
    day = 1;
}


/**

###############################
#                             #
# GETTERS AND SETTERS SECTION #
#                             #
###############################
*/

int Date::get_day(){
    return day;
}

int Date::get_month(){
    return month;
}

int Date::get_year(){
    return year;
}

Time Date::get_time(){
    return time;
}

void Date::set_day(int nday){
    day = nday;
}

void Date::set_month(int mth){
    month = mth;
}

void Date::set_year(int nyear){
    year = nyear;
}
void Date::set_time(Time ntime){
    time = ntime;
}


ostream& operator<<(ostream& out, const Date& t){
    out<<t.day<<"."<<t.month<<"."<<t.year<<" "<<t.time<<endl;
    return out;
}



/**

###############################
#                             #
# DATES FUNCTIONS SECTION     #
#                             #
###############################
*/


/**Converts the date to amount of julian days*/
int gregorian_to_julian_days(Date our_date){
    int a_coeficient = (14 - our_date.get_month())/12;
    int y = our_date.get_year() + 4800 - a_coeficient;
    int m = our_date.get_month()+ 12*a_coeficient -3;
    int div1 = (153*m+2)/5;
    int div2 = y/4;
    int div3 = y/100;
    int div4 = y/400;
    return our_date.get_day()+div1+365*y+div2-div3+div4-32045;
}

/**Difference between dates, in days*/
int day_difference(Date first_date, Date second_date){
    int day_1 = gregorian_to_julian_days(first_date);
    int day_2 = gregorian_to_julian_days(second_date);
    if (day_1 > day_2) return day_1 - day_2;
    return day_2 - day_1;
}


/**Checks if input year is the leap year*/
bool is_year_leap(Date date){
    int year = date.get_year();
    return (year%400==0)||((year%4==0)&&(year%100!=0));
}

/**Gets day of the week by date as number (0 - sunday, 6 - saturday*/
int get_day_of_week_numeric(Date our_date){
    int a, y, m;
    a = ( 14 - our_date.get_month()) / 12;
    y = our_date.get_year() - a;
    m = our_date.get_month() + 12 * a - 2;
    return (7000 + (our_date.get_day() + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12 ))%7;
}

/**Gets day of the week by date as string*/
char* get_day_of_week(Date our_date){
    return DAYS_OF_WEEK[get_day_of_week_numeric(our_date)];
}

/**Gauss'es Day of Catolic Easter Calculation Algorithm*/
Date calculate_easter_date_catolic(Date current_date){
    //More info: https://en.wikipedia.org/wiki/Date_of_Easter#Gauss's_Easter_algorithm
    int intYear = current_date.get_year();
    int a, b, c, d, e, f, g, h, i, j, k, m, p;
    a=intYear%19;
    b=intYear/100;
    c=intYear%100;
    d=b/4;
    e=b%4;
    f=(b+8)/25;
    g=(b-f+1)/3;
    h=((19*a)+b-d-g+15)%30;
    i=c/4;
    j=c%4;
    k=(32+(2*e)+(2*i)-h-j)%7;
    m=(a+(11*h)+(22*k))/451;
    int easterMonth=(h+k-(7*m)+114)/31;
    p=(h+k-(7*m)+114)%31;
    int easterDay=p+1;
    return Date(intYear, easterMonth, easterDay, Time());
}

