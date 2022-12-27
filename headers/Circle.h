#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <vector>
#include "Shape.h"
#include "Point.h"

#define M_PI 3.14159265358979323846

class Circle : public Shape{
    private:
        std::vector<Point> points;
        std::string name = "Circle";
        double r;
    public:

        /**Constructor by vector of Points*/
        Circle(std::vector<Point> _points) {
            points = _points;
            r = abs(points[1].distToPoint(points[0]));
        }

        /**whoAmI method override*/
        std::string whoAmI() override{
            return name;
        }

        /**Override method of getting perimeter*/
        double getPerimeter() override{
            return 2 * M_PI * r;
        }

        /**Override of getting square method*/
        double getArea() override {
            return M_PI * r * r;
        }


};


#endif // CIRCLE_H_INCLUDED
