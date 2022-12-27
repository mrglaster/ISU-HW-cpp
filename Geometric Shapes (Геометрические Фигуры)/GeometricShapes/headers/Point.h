#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <cmath>
using namespace std;

class Point{
    private:
        int x = 0;
        int y = 0;
    public:
        Point();
        Point(int _x, int _y);
        ~Point();
        void printPoint();
        int getX();
        int getY();

        double distToPoint(Point distPoint);
        double pointVecMul(Point anotherPoint);

};


#endif // POINT_H_INCLUDED
