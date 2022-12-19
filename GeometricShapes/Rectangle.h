#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <iostream>
#include "Shape.h"
using namespace std;

#include "Point.h"


class Rectangle : public Shape {
    private:
        double  width;
        double  height;


    public:

        /**Simple RECTANGLE constructor*/
        Rectangle(double w, double h){
            if (w <=0 || h <= 0){
                cout<<"Unable to create rectangle with shapes: "<<w<<" , "<<h<<endl;
                exit(-1);
            }
            width = w;
            height = h;
        }

        /**Constructor by 2 Point class objects*/
        Rectangle(Point lu_point, Point rd_point){
            width = lu_point.distTo(Point(rd_point.getX(), lu_point.getY()));
            height = lu_point.distTo(Point(lu_point.getX(), rd_point.getY()));
        }

        /**Returns SQUARE of the RECTANGLE*/
        double getSquare() override {
            return width * height;
        }

        /**Returns PERIMETER of the RECTANGLE*/
        double getPerimeter() override {
            return 2 * (width + height);
        }

        /**Shows type of the figure*/
        void showFigureType() override {
            cout<<"Hey! I'm the rectangle! My width = "<<width<<"  height = "<<height<<" Square = "<<getSquare()<<" and perimeter = "<<getPerimeter()<<endl;
        }
};

#endif // RECTANGLE_H_INCLUDED
