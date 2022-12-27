#include "../headers/Point.h"
#include <math.h>
#include <iostream>

/**Basic Point constructor*/
Point::Point(int _x, int _y){
    x = _x;
    y = _y;
}

/**Point initialization constructor*/
Point::Point(){
    x = 0;
    y = 0;
}

/**Point destructor*/
Point::~Point(){
    x = 0;
    y = 0;
}

/**X getter*/
int Point::getX(){
    return x;
}

/**Y getter*/
int Point::getY(){
    return y;
}

/**Returns distance from current point to another one*/
double Point::distToPoint(Point distPoint){
    return  sqrt((distPoint.getX() - x) *  (distPoint.getX() -x) + (distPoint.getY() - y) * (distPoint.getY() - y));
}


double Point::pointVecMul(Point anotherPoint){
    return y * anotherPoint.getX() - x * anotherPoint.getY();
}

/**Prints point*/
void Point::printPoint(){
    std::cout<<"("<<x<<";"<<y<<")"<<std::endl;
}

