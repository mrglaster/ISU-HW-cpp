#include <iostream>
#include <ostream>
#include "TimeClass.h"
using namespace std;

/**

###############################
#                             #
#    CONSTRUCTORS SECTION     #
#                             #
###############################
*/



Time::Time(){
    hours = 0;
    minutes =0;
    seconds = 0;
    time_valid_check();
}

Time::~Time(){
    hours = 0;
    minutes = 0;
    seconds = 0;
    time_valid_check();
}

Time::Time(int hours_g){
    hours = hours_g;
    minutes = 0;
    seconds = 0;
    time_valid_check();
}

Time::Time(int hours_g, int minutes_g){
    hours = hours_g;
    minutes = minutes_g;
    seconds = 0;
    time_valid_check();
}

Time::Time(int hours_g, int minutes_g, int seconds_g){
    hours = hours_g;
    minutes = minutes_g;
    seconds = seconds_g;
    time_valid_check();
}

/**

###############################
#                             #
# GETTERS AND SETTERS SECTION #
#                             #
###############################
*/


int Time::get_keepinmind(){
    return keep_in_mind;
}

int Time::get_hours(){
    return hours;
}

int Time::get_minutes(){
    return minutes;
}

int Time::get_seconds(){
    return seconds;
}

void Time::set_hours(int hour){
    hours = hour;
}

void Time::set_minutes(int minute){
    minutes = minute;
}

void Time::set_seconds(int second){
    seconds = second;
}

void Time::setTime(int h, int m, int s){
    hours = h;
    minutes = m;
    seconds = s;
}

void Time::update_keepinmind(int update_value){
    keep_in_mind+=update_value;
}


/**

###############################
#                             #
# OPERATORS OVERLOAD SECTION  #
#                             #
###############################
*/


ostream& operator<<(ostream& out, const Time& t){
    out<<t.hours<<":"<<t.minutes<<":"<<t.seconds<<endl;
    return out;
}



Time& Time::operator+=(const Time& t){
    seconds+= t.seconds;
    minutes+= t.minutes;
    hours += t.hours;
    simplify();
}



Time Time::operator +(const Time &t) const {
    Time result = Time(hours + t.hours, minutes + t.minutes, seconds + t.seconds);
    result.simplify();
    return result;
}


/**

###############################
#                             #
#      FOREIGN FUNCTIONS      #
#                             #
###############################
*/


void Time::simplify(){
    if(seconds >=60){
        seconds-=60;
        minutes++;
    }
    if(minutes >=60){
        minutes-=60;
        hours++;
    }
    if(hours >= 24){
        hours-=24;
        keep_in_mind+=1;
    }
}

void Time::time_valid_check(){
    if(seconds > 60 || minutes > 60 || hours > 24 || seconds < 0 || minutes < 0 || hours < 0 ){
        cout<<"Wrong time! Can't be real time: "<<hours<<" : "<<minutes<<" : "<<seconds<<endl;
        exit(-1);
    }
}
