#include <iostream>
#include "TimeClass.h"
#include "DateClass.h"
using namespace std;

int main()
{
    Date date = Date(2022, 11, 21, Time());
    cout<<calculate_easter_date_catolic(date);
    return 0;
}
