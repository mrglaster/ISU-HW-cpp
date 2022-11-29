#ifndef TIMECLASS_H_INCLUDED
#define TIMECLASS_H_INCLUDED

#include <iostream>
using namespace std;

class TimeException{};

class Time{
    private:
        int hours;
        int minutes;
        int seconds;
        int keep_in_mind = 0;

    public:

         //Constructors
         Time();
         Time(int hours_g);
         Time(int hours_g, int minutes_g);
         Time(int hours_g, int minutes_g, int seconds_g);
         ~Time();

         //Operators overload
         Time& operator +=(const Time& t);
         Time operator +(const Time& t) const;
         Time operator -(const Time& t);
         bool operator ==(const Time& t) const;
         friend ostream& operator<<(ostream& os, const Time& t);

         //Getters
         int get_hours();
         int get_minutes();
         int get_seconds();
         int get_keepinmind();

         //Setters
         void set_hours(int hour);
         void set_minutes(int minute);
         void set_seconds(int second);
         void setTime(int h, int m, int s);
         void update_keepinmind(int update_value);


         //Foreign functions
         void simplify();
         void time_valid_check();
};

#endif // TIMECLASS_H_INCLUDED
