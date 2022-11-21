#ifndef DATECLASS_H_INCLUDED
#define DATECLASS_H_INCLUDED

#include <iostream>
#include "TimeClass.h"
#include <strings.h>


using namespace std;
class DateException{};

class Date{
    private:
        int year = 1900;
        int month = 1;
        int day = 1;
        Time time;
    public:
        Date(int yr, int mth, int d, Time tm);
        Date();
        friend ostream& operator<<(ostream& os, const Date& t);
        int get_year();
        int get_month();
        int get_day();
        Time get_time();
        void set_year(int year);
        void set_day (int day);
        void set_month(int month);
        void set_time(Time time);



};



#endif // DATECLASS_H_INCLUDED


int gregorian_to_julian_days(Date our_date);

int day_difference(Date first_date, Date second_date);

int get_day_of_week_numeric(Date our_date);

bool is_year_leap(Date date);

char* get_day_of_week(Date our_date);

Date calculate_easter_date_catolic(Date current_date);

