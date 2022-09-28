#include <iostream>>
#include "geometry.h"
#include "file.h"
#include "search.h"
using namespace std;

void findAndInsert(Triangle* trArray, int length, const Triangle& triangle){
	int pos;
	for (pos = length - 1; pos >= 0; pos--)
	{
		if (triangle.area <= trArray[pos].area)
			break;
	}
	pos++;
	if (pos == length)
		return;
	for (int m = length - 2; m >= pos; m--)
		trArray[m + 1] = trArray[m];
	trArray[pos] = triangle;
}

void searchLargestTriangles(const Point* pointArray, int pointNum, Triangle* trArray, int maxTrNum) {
    cout<<"Searching the largest triangles! "<<endl;
	if (maxTrNum <= 0)
		return;
	for (int i = 0; i < maxTrNum; i++)
		clearTriangle(trArray[i]);
	Triangle triangle;
	for (int i = 0; i < pointNum; i++) {
		triangle.vertex[0] = pointArray[i];
		for (int j = i + 1; j < pointNum; j++) {
			triangle.vertex[1] = pointArray[j];
			for (int k = j + 1; k < pointNum; k++) {
				triangle.vertex[2] = pointArray[k];
				calcTriangleArea(triangle);
				findAndInsert(trArray, maxTrNum, triangle);
			}
		}
	}
}
