
#include <iostream>
#include <vector>
#include <memory>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;


int main()
{
    vector< unique_ptr<Shape>> shapes;
    Triangle abc = Triangle (Point(1, 2), Point(3, 9), Point(4, 6));
    std::unique_ptr<Shape> trianglePtr(new Triangle( std::move(abc) ) );
    shapes.push_back(std::move(trianglePtr));
    cout<<abc.getSquare();
    return 0;
}
