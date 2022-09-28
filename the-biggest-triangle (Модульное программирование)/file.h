#ifndef _FILE_
#define _FILE_

int countPoints(char* fileName);

bool readPoints(char* fileName, Point* pointArray, int maxPointNum);
bool writeTriangles(char* fileName, Triangle* trArray, int trNum);

#endif
