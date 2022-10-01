//
// Created by ASUS on 2022. 09. 28..
//

#ifndef CPP_2022_UTIL_H
#define CPP_2022_UTIL_H

#include "Point.h"


double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
void closestPoints(Point* points, int numPoints);
void farthestPoints(Point *points, int numPoints);
void deletePoints(Point* points);



#endif //CPP_2022_UTIL_H
