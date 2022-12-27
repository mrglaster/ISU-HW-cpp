#include "../headers/Circle.h"


Circle::Circle(std::vector<Point> _points) {
    points = _points;
    r = abs(points[1].distToPoint(points[0]));
}

double Circle::getPerimeter() override{
    return 2 * M_PI * r;
}

double Circle::getSquare() override{
    return M_PI * r * r;
}

std::string Circle::whoAmI() override{
    return name;
}
