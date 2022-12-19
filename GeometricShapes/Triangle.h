#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "Shape.h"
#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

class Triangle : public Shape {
    private:
        Point a;
        Point b;
        Point c;
    public:

        /**Three Points Constructor*/
        Triangle(Point as, Point bs, Point cs){
            a = as;
            b = bs;
            c = cs;
        }

        /**Find Perimeter of the triangle*/
        double getPerimeter() override {
            double ab = a.distTo(b);
            double ac = a.distTo(c);
            double bc = b.distTo(c);
            return ab + ac + bc;
        }

        /**Get Square or triangle using Heron's theorem*/
        double getSquare() override {
            double ab = a.distTo(b);
            double ac = a.distTo(c);
            double bc = b.distTo(c);
            return 0.25 * sqrt(4 * ab * ab * bc * bc - (ab * ab + bc * bc - ac * ac) * (ab * ab + bc * bc - ac * ac));
        }

        /**Writes, what the Figure this is*/
        void showFigureType() override {
            cout<<"Hi! I'm the Triangle with points: "<<endl;
            a.printPoint();
            b.printPoint();
            c.printPoint();
        }
};


#endif // TRIANGLE_H_INCLUDED
