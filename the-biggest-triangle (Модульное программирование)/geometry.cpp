#include <math.h>
#include "geometry.h"

void clearPoint(Point& p) {
	p.x = p.y = 0;
}

void clearTriangle(Triangle& tr) {
	for (int i = 0; i < 3; i++)
		clearPoint(tr.vertex[i]);
}


double distance_bPoints(const Point& a, const Point& b) {
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

double calcAreaBySides(double a, double b, double c){
	double p2 = (a + b + c) / 2.0;
	if (p2 <= 0.0 || p2 <= a || p2 <= b || p2 <= c)
		return 0.0;
	return sqrt(p2 * (p2 - a) * (p2 - b) * (p2 - c));
}

double calcTriangleArea(Triangle& tr){
	Point* v = tr.vertex;
	double a_side = distance_bPoints(v[0], v[1]);
	double b_side = distance_bPoints(v[1], v[2]);
	double c_side = distance_bPoints(v[2], v[0]);
	return tr.area = calcAreaBySides(a_side, b_side, c_side);
}

bool triangleExists(Triangle tr_sub){
    Point* triag_points = tr_sub.vertex;
    if(((triag_points[2].x - triag_points[0].x) / (triag_points[1].x - triag_points[0].x) == (triag_points[2].y - triag_points[0].y) / (triag_points[1].y - triag_points[0].y))) return false;
    return true;
}
