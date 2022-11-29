#ifndef DATEIO_H_INCLUDED
#define DATEIO_H_INCLUDED

#include "DateClass.h"

//char* MONTH_NAMES[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//Format day.month.full year
int const DATE_DMY = 1;

//Format day.month as string.full year
int const DATE_DSY = 2;

//Short date format day.month.year
int const  DATE_SHORT = 3;

int const  DATE_WITH_TIME = 4;

class DateIOException{};

//Is date valid?
bool isValidDate(string date, int format);

//Is date's format valid
bool isValidFormat(int format);

//Print date with format
void print_date(Date date, int format);

//Reads date from format
Date read_date();

//Selects date's format
int select_date_format();


#endif // DATEIO_H_INCLUDED
