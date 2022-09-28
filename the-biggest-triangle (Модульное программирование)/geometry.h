#ifndef _GEOMETRY_
#define _GEOMETRY_

struct Point {
	double x, y;
};

struct Triangle {
	Point vertex[3];
	double area;
};

//Calculating stuff
double distance_bPoints(const Point& a, const Point& b);
double calcAreaBySides(double a, double b, double c);
double calcTriangleArea(Triangle& tr);

//Existance checks
bool triangleExists(Triangle tr_sub);


//Cleaning stuff
void clearPoint(Point& p);
void clearTriangle(Triangle& tr);



#endif
