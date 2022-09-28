#include <fstream>
#include <iostream>
#include <limits>
#include <string>

#include "geometry.h"
#include "file.h"
using namespace std;


// Operators overloading
istream& operator >> (istream& in, Point& p){
    in >> p.x >> p.y;
    return in;
}

ostream& operator <<(ostream& out, const Point& p){
    out << "(" << p.x << " " << p.y << ")";
    return out;
}
ostream& operator <<(ostream& out, const Triangle& tr){
    out << "A=" << tr.vertex[0] <<
        " B=" << tr.vertex[1] <<
        " C=" << tr.vertex[2] <<
        " S=" << tr.area;
    return out;
}


bool is_number(string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)){
        it++;
    }
    return !s.empty() && it == s.end();
}

// Get amount of points in file
int countPoints(char* fileName){
    ifstream in(fileName);
    if (!in.is_open()) return -1;
    string x, y;
    int i;
    for (i = 0; ; i++){
        in >> x >> y;
        if(!is_number(x) || !is_number(y)){
            cout<<endl<<"Error! You have wrong-typed data in your file!"<<endl;
            exit(-2);
        }
        if (in.fail()){
            if(i<4){
                cout<<"Data error! As minimum 4 points are required!"<<endl;
                exit(-3);
            }
            break;
        }
    }
    return i;
}


// Reading points
bool readPoints(char* fileName, Point* pointArray, int maxPointNum){
    ifstream in(fileName);
    if (!in.is_open())
        return false;
    for (int i = 0; i < maxPointNum; i++){
        Point curpoint;
        in >> pointArray[i];
    }
    return true;
}

//Write damn trianglez
bool writeTriangles(char* fileName, Triangle* trArray, int trNum){
    ofstream out(fileName);
    if (!out.is_open())
        return false;
    for (int i = 0; i < trNum; i++){
        if(i!=0 && trArray[i].area==trArray[i-1].area){
            cout<<"We have a triangle with the same area: "<<trArray[i]<<". So it won't be written to file"<<endl;
        }
        else{
            if(!triangleExists(trArray[i])){
                trArray[i].area = 0;
                cout<<"We have unexisting triangle here: "<<trArray[i]<<" .  But we'll add it to the file"<<endl;
                out << "#" << i + 1 << ": " << trArray[i] << " TRIANGLE DOESN'T EXIST!" <<endl;
            }
            else{
                out << "#" << i + 1 << ": " << trArray[i] <<endl;
            }
        }
    }
    return true;
}
