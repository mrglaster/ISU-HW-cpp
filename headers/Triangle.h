#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "Shape.h"

class Triangle : public Shape{
    private:

        std::vector<Point> points;
        std::string name = "Triangle";
        size_t pointsAmount;

    public:

        /**Constructor by vector of Points*/
        Triangle(std::vector<Point> _points) {
            points = _points;
            pointsAmount = points.size();
            points.resize(pointsAmount + 1);
            points[pointsAmount] = points[0];
        }

        /**Getting name method override*/
        std::string whoAmI() override {
            return name;
        }

        /**Getting Perimeter method override*/
        double getPerimeter() override{
            double sum = 0;
            for (int i = 0; i < pointsAmount; i++) sum+=points[i].distToPoint(points[i+1]);
            return sum;

        }

        /**Getting square method override*/
        double getArea() override{
            int sum = 0;
            for (int i = 1; i <= pointsAmount; i++) sum += points[i].pointVecMul(points[i-1]);
            return abs((double)sum/2);
        }






};

#endif // TRIANGLE_H_INCLUDED
