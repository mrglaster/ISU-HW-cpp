#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;
#include "DateIO.h"

/**Fall if wrong int date format*/
void _fallout_date_format(){
    cout<<"Wrong date format!"<<endl;
    exit(-1);
}

/**Date IO format selector*/
int select_date_format(string type_action){
    cout<<"  Select the date "<<type_action<<" format: "<<endl;
    cout<<"     1) Day.Month.FullYear (like 1.01.2001)"<<endl;
    cout<<"     2) Day.Month as String.Fullyear (like 1 January 2022)"<<endl;
    cout<<"     3) DD.MM.YY (like 01.01.01)"<<endl;
    cout<<"     4) yyyy-MM-ddThh:mm:ss (like 2021-12-21T07:54:34) "<<endl;
    int result = 0;
    cin >> result;
    if (cin.fail() || !isValidFormat(result)) _fallout_date_format();
    return result;
}


/**Converts string month to number*/
int month_to_number(string month){
    char* MONTH_NAMES[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for(int i = 0; i<12; i++){
        if(month == MONTH_NAMES[i]) return i+1;
    }
    cout<<"Unknown month name: "<<month<<endl;
    exit(-1);
}

/**Converts number to month*/
string number_to_month(int number){
    int rn = number - 1;
    if (rn < 0 || rn > 11){
        cout<<"Wrong month number: "<<rn<<endl;
        exit(-1);
    }
    char* MONTH_NAMES[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return MONTH_NAMES[rn];

}

/**Reads date in format day.month.year*/
Date _read_dmy(){
    string input = "";
    int year, month, day;
    cin >> input;
    stringstream ss(input);
    char ch;
    ss >> day >> ch >> month >> ch >> year;
    return Date(year, month, day, Time());
}

/**Reads date in format day.month as string.year*/
Date _read_dsy(){
    int day, year;
    string month;
    cin >> day >> month >> year;
    if(day<=0 || day > 31) {
        cout<<"Impossible amount of days: "<<day<<endl;
        exit(-1);
    }
    return  Date(year, month_to_number(month), day,  Time());
}

/**Reads date in short format*/
Date _read_short(){
    int day, month, year_postfix;
    string input;
    cin>>input;
    stringstream ss(input);
    char ch;
    ss >> day >> ch >> month >> ch >> year_postfix;
    if(year_postfix >= 30) year_postfix = 1900+year_postfix;
    else year_postfix = 2000+year_postfix;
    return  Date(year_postfix, month, day,  Time());
}

/**Reads date in format yyyy-MM-ddThh:mm:ss*/
Date _read_date_time(){
    int year, month, day, hours, minutes, seconds;
    string input;
    cin>>input;
    if (input.find('T') == std::string::npos){
        cout<<"Wrong input date! T expected!"<<endl;
        exit(-1);
    }
    std::replace(input.begin(), input.end(), 'T', '-');
    stringstream ss(input);
    char ch;
    ss >> year >> ch >> month >> ch >> day >>hours >> ch >>minutes >> ch >> seconds;
    return Date(year, month, day, Time(abs(hours), abs(minutes), abs(seconds)));

}
/**Reads date from keyboard*/
Date read_date(){
    int format = select_date_format("Input");
    switch(format){
    case DATE_DMY: //Works!
        return _read_dmy();
        break;
    case DATE_DSY: //Works!
        return _read_dsy();
        break;
    case DATE_SHORT:
        return _read_short();
        break;

    case DATE_WITH_TIME:
        return _read_date_time();
        break;
    }
}

/**Date's format validation check*/
bool isValidFormat(int format){
    return format >= 1 && format <= 4;
}

/**Prints date in DMY format*/
void _print_date_dmy(Date date){
    string str_day = std::to_string(date.get_day());
    string str_month = std::to_string(date.get_month());
    if(date.get_day() < 10) str_day = "0"+ str_day;
    if (date.get_month() < 10) str_month = "0" + str_month;
    cout<<str_day<<"."<<str_month<<"."<<date.get_year()<<endl;
}

/**Prints date in DSY format*/
void _print_date_dsy(Date date){
    string postfix = "";
    if(date.get_day()%10 == 1 && date.get_day() != 11 || date.get_day() == 1) postfix = "st ";
    else if(date.get_day()%10 == 2 && date.get_day() != 12 || date.get_day() == 2) postfix = "nd ";
    else if(date.get_day()%10 == 3 && date.get_day() != 13 || date.get_day() == 3) postfix = "rd ";
    else postfix = "th ";
    cout<<date.get_day()<<postfix<<number_to_month(date.get_month())<<" "<<date.get_year()<<endl;
}

/**Print date in short format*/
void _print_date_short(Date date){
    string str_day = std::to_string(date.get_day());
    string str_month = std::to_string(date.get_month());
    if(date.get_day() < 10) str_day = "0"+ str_day;
    if (date.get_month() < 10) str_month = "0" + str_month;
    string post = "0";
    if(date.get_year()%100 < 10) post+=std::to_string(date.get_year()%100);
    else post = std::to_string(date.get_year());
    cout<<str_day<<"."<<str_month<<"."<<post<<endl;
}

/**Prints date in date-and-time format*/
void _print_date_time(Date date){
    string str_day = std::to_string(date.get_day());
    string str_month = std::to_string(date.get_month());
    if(date.get_day() < 10) str_day = "0"+ str_day;
    if (date.get_month() < 10) str_month = "0" + str_month;
    cout<<date.get_year()<<"-"<<str_month<<"-"<<str_day<<"T"<<date.get_time().get_hours()<<":"<<date.get_time().get_minutes()<<":"<<date.get_time().get_seconds()<<endl;
}

/**Prints date in selected format*/
void print_date(Date date, int format){
    if (!isValidFormat(format)) _fallout_date_format();
    switch(format){
        case DATE_DMY:
            _print_date_dmy(date);
            break;
        case DATE_DSY:
            _print_date_dsy(date);
            break;
        case DATE_SHORT:
            _print_date_short(date);
            break;
        case DATE_WITH_TIME:
            _print_date_time(date);
            break;
    }
}


