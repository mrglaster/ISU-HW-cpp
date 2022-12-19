#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
using namespace std;

class Point{
    private:
        int x = 0;
        int y = 0;
    public:
        ~Point();
        Point();
        Point(int new_x, int new_y);
        int getX();
        int getY();
        double distTo(Point p_end);
        void printPoint();
};



#endif // POINT_H_INCLUDED
