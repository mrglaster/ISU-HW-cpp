#include "../headers/Demonstration.h"
#include "../headers/Point.h"
#include "../headers/Circle.h"
#include "../headers/Polygon.h"
#include "../headers/Rectangle.h"
#include "../headers/Triangle.h"

/**Demonstration of work. */
void demonstrateShapes(char filename[]){
    cout<<"Working with file: "<<filename<<endl<<endl;
    Point a1(3, 4), b1(5, 11), c1(12, 8), d1(9, 5), e1(5, 6);
    Point a2(0, 0), b2(0, 1),  c2(1, 1),  d2(1, 0);
    Point a3(0, 0), b3(5, 0),  c3(3, 3);
    Point a4(1, 1), b4(5, 1);

    std::vector<Point> points1, points2, points3, points4;
    points1.push_back(a1), points1.push_back(b1), points1.push_back(c1), points1.push_back(d1), points1.push_back(e1);
    points2.push_back(a2), points2.push_back(b2), points2.push_back(c2), points2.push_back(d2);
    points3.push_back(a3), points3.push_back(b3), points3.push_back(c3);
    points4.push_back(a4), points4.push_back(b4);

    std::vector<Shape*> figures;
    Circle demo_circle(points4);
    Rectangle demo_rectangle(points2);
    Triangle demo_triangle(points3);
    Polygon demo_pointvec_polygon(points1);
    Polygon demo_ffile_polygon(filename);
    figures.push_back(&demo_circle);
    figures.push_back(&demo_rectangle);
    figures.push_back(&demo_pointvec_polygon);
    figures.push_back(&demo_triangle);
    figures.push_back(&demo_ffile_polygon);

    for (int i = 0; i < figures.size(); i++) {
        double sq = figures[i]->getArea();
        double pr = figures[i]->getPerimeter();
        std::cout <<figures[i]->whoAmI() <<" "<< "with area" << " = " << sq << " and "<<"perimeter" << " = " << pr << std::endl;
    }

}
