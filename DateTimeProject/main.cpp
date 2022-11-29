#include <iostream>
#include "DateClass.h"
#include "DateIO.h"

/**Demonstration of class Date*/
void datetime_demonstration(){
    Date date_1 = read_date();
    Date date_2 = read_date();
    system("CLS");
    cout<<"Date I: "<<endl;
    for(int i = 0; i < 4; i++){
        cout<<i+1<<") ";
        print_date(date_1, i+1);
    }
    cout<<endl<<endl<<endl;

    cout<<"Date II: "<<endl;
    for(int i = 0; i < 4; i++){
        cout<<i+1<<") ";
        print_date(date_2, i+1);
    }
    cout<<endl<<endl;
    cout<<"Difference between dates in days: "<<day_difference(date_1, date_2)<<endl<<endl;

    cout<<"Day of the week for first date is: "<<get_day_of_week(date_1)<<endl;
    cout<<"Day of the week for second date is: "<<get_day_of_week(date_2)<<endl;

    cout<<endl<<endl;

    if(date_1.get_year() == date_2.get_year()) {
        cout<<"Orthodox easter for both dates year: "; print_date(calculate_easter_date_orthodox(date_1), DATE_DSY); cout<<endl;
        cout<<"Catolic easter for both dates year: "; print_date(calculate_easter_date_catolic(date_1), DATE_DSY); cout<<endl;
    }

    else {
        cout<<"Orthodox easter for First date's year: "; print_date(calculate_easter_date_orthodox(date_1), DATE_DSY); cout<<endl;
        cout<<"Catolic easter for First date's year: "; print_date(calculate_easter_date_catolic(date_1), DATE_DSY); cout<<endl;

        cout<<"Orthodox easter for Second date's year: "; print_date(calculate_easter_date_orthodox(date_2), DATE_DSY); cout<<endl;
        cout<<"Catolic easter for Second date's year: "; print_date(calculate_easter_date_catolic(date_2), DATE_DSY); cout<<endl;
    }

    if(is_year_leap(date_1)) cout <<"Year "<<date_1.get_year()<<" is leap"<<endl;
    else cout <<"Year "<<date_1.get_year()<<" is not leap"<<endl;

    if(date_1.get_year() != date_2.get_year()){
        if(is_year_leap(date_1)) cout <<"Year "<<date_1.get_year()<<" is leap"<<endl;
        else cout <<"Year "<<date_1.get_year()<<" is not leap"<<endl;
    }
}



int main()
{
    datetime_demonstration();

    return 0;
}
