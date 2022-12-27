#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"

class Rectangle : public Shape{

    private:
        std::vector<Point> points;
        std::string name = "Rectangle";
        size_t pointsAmount;
        void updateName(std::string new_name){
            name = new_name;
        }

    public:

        /**Rectangle constructor by vector of Points*/
        Rectangle(std::vector<Point> _points) {
            points = _points;
            pointsAmount = points.size();
            points.resize(pointsAmount + 1);
            points[pointsAmount] = points[0];
            if (sqrt(getArea()) * 4 == getPerimeter()) updateName("Square");

        }

        /**What the figure I am?*/
        std::string whoAmI(){
            return name;
        }

        /**Getting Perimeter method override*/
        double getPerimeter() override{
            double sum = 0;
            for (int i = 0; i < pointsAmount; i++) sum+=points[i].distToPoint(points[i+1]);
            return sum;
        }

        /**Getting Square method override*/
        double getArea() override{
            int sum = 0;
            for (int i = 1; i <= pointsAmount; i++)
                sum += points[i].pointVecMul(points[i-1]);
            return abs((double)sum / 2);
        }

};


#endif // RECTANGLE_H_INCLUDED
