#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

int global_year = 0;
int global_month = 0;
int global_day = 0;



string enter(int t) {
    if (t < 10) return "0";
    return "";
}


/**Writes required data from moon file*/
void process_moon_file(string filename){
    int months_days[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int OneDayRows[3] = {144, 1440, 86400};
    int i;
    int date, skip = 0, past_time, time, rise = -1, set = -1, climax, one_day;
    double angle, past_angle, max_angle = 0.0;

    if (global_year < 2010) one_day = OneDayRows[0];
    else if (global_year < 2023) one_day = OneDayRows[1];
    else one_day = OneDayRows[2];

    ifstream file(filename);
    string current_row;
    getline(file, current_row);
    for (i = 0; i < global_month - 1; i++) {
        skip += months_days[i] * one_day;
    }

    if ((global_year % 4 == 0) && (global_month > 2)) skip += one_day;
    skip = skip + (global_day - 1) * one_day;
    if (skip > 0) skip--;
    for (i = 0; i < skip; i++) {
        getline(file, current_row);
    }

    file >> current_row >> past_time >> current_row >> current_row >> past_angle >> current_row >> current_row >> current_row;
    do {
        file >> date >> time >> current_row >> current_row >> angle >> current_row >> current_row >> current_row;
        if (max_angle < angle) {
            max_angle = angle;
            climax = time;
        }

        if (past_angle < 0 && angle > 0) {
            time = time / 10000 * 3600 + time / 100 % 100 * 60 + time % 100;
            past_time = past_time / 10000 * 3600 + past_time / 100 % 100 * 60 + past_time % 100;
            rise = past_time + (time - past_time) / ((past_angle - angle) / past_angle);
        }

        if (past_angle > 0 && angle < 0) {
            time = time / 10000 * 3600 + time / 100 % 100 * 60 + time % 100;
            past_time = past_time / 10000 * 3600 + past_time / 100 % 100 * 60 + past_time % 100;
            set = past_time + (time - past_time) / ((past_angle - angle) / past_angle);
        }

        past_time = time;
        past_angle = angle;
    } while ((date % 100 == global_day) || (set == -1) || (rise == -1));

    cout<<endl<<endl;
    cout << "Date: " << global_day<<"."<<global_month<<"."<<global_year<<endl;
    cout << "Moon rise: " << enter(rise / 3600) << rise / 3600 << ":" << enter(rise % 3600 / 60) << rise % 3600 / 60 << ":" << enter(rise % 60) << rise % 60 << endl;
    cout << "Moon climax: " << enter(climax / 10000) << climax / 10000 << ":" << enter(climax / 100 % 100) << climax / 100 % 100 << ":" << enter(climax % 100) << climax % 100 << endl;
    cout << "Moonset: " << enter(set / 3600) << set / 3600 << ":" << enter(set % 3600 / 60) << set % 3600 / 60 << ":" << enter(set % 60) << set % 60 << endl;
}



/**Checks the date's validation*/
void date_check(){
    if (global_year < 1998 || global_year > 2023 || global_month < 0 || global_month > 12 || global_day < 0 || global_day > 31){
        cout<<"Wrong date!"<<endl;
        exit(-1);
    }
}

/**Returns name of the moon file*/
string get_filename(){
    string input;
    cout<<"Write the date in format YYYY.MM.DD."<<endl;
    cin >> input;
    stringstream ss(input);
    char separator;
    ss >> global_year >> separator >> global_month >> separator >> global_day;
    date_check();
    string result = "moon"+std::to_string(global_year)+".dat"+'\0';
    cout<<result<<endl;
    return result;
}

/**The main function*/
int main(){
    string filename = get_filename();
    process_moon_file(filename);
}
