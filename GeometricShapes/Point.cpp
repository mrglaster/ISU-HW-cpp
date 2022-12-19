#include <cmath>
#include <iostream>
#include "Point.h"
using namespace std;


/**Point Destrictor*/
Point::~Point(){
    x = 0;
    y = 0;
}

/**Basic constroctor*/
Point::Point(){
    x = 0;
    y = 0;
}

/**Constructor with X and Y */
Point::Point(int new_x, int new_y){
    x = new_x;
    y = new_y;
}

/**X getter*/
int Point::getX(){
    return x;
}

/**Y getter*/
int Point::getY(){
    return y;
}


/**Calculates distance to other Point*/
double Point::distTo(Point p_end){
   return sqrt((p_end.getX() - x) *  (p_end.getX() -x) + (p_end.getY() - y) * (p_end.getY() - y));
}

void Point::printPoint(){
    cout<<"("<<x<<" ; "<<y<<")"<<endl;
}
