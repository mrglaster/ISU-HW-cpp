#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Shape.h"
#include "Point.h"
using namespace std;

class Circle : public Shape{
    private:
        double radius;

    public:

        /**CIRCLE constructor working with RADIUS*/
        Circle(double r){
            radius = r;
        }

        /**CIRCLE constructor by center and end of the triangle points origins*/
        Circle (Point endOfCircle, Point centerCoordinate){
            radius = centerCoordinate.distTo(endOfCircle);
        }

        /**SQUARE of the CIRCLE*/
        double getSquare() override{
            return radius * radius * M_PI ;
        }

        /**Returns RADIUS of the CIRCLE*/
        double get_diameter(){
            return 2 * radius;
        }

        /**Returns LENGTH of the CIRCLE*/
        double getPerimeter() override{
            return 2 * M_PI * radius;
        }

        /**Shows type of the FIGURE*/
        void showFigureType() override{
            cout<<"Hey! I'm CIRCLE! My r = "<<radius<<", Square = "<<getSquare()<<" and Perimeter = "<<getPerimeter()<<endl;
        }

};

#endif // CIRCLE_H_INCLUDED
