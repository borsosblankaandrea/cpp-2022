//
// Created by ASUS on 2022. 09. 28..
//

#include <cmath>
#include "util.h"


double distance(const Point& a, const Point& b){
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {

    if (distance(a,b) == distance(b,c) && distance(a,b) == distance(c,d) && distance(a,b) == distance(d,a)){
        if(distance(a,c) == distance(b,d) && distance(a,c)!= 0){
            return 1;
        }
    }
    return 0;
}

Point *createArray(int numPoints) {
    Point * points = new Point[numPoints+1];
    srand(time(NULL));

    for(int i=0; i<numPoints;i++){
        int x,y;
        x = rand() % 2001;
        y = rand() % 2001;

        Point point(x,y);
        points[i] = point;

        //points[i].print();
    }
    return points;
}

void printArray(Point *points, int numPoints) {
    for(int i=0; i<numPoints; i++){
        points[i].print();
    }
}

/// pair<Point, Point> nem tudom hogy kell hasznalni
void closestPoints(Point *points, int numPoints) {
    int minDistance=3000; // A pontok koordinátái legyenek a 0 és 2000 közötti egész számok ([0, 2000]). -> legnagyobb tavolsag 2000*sqrt(2) -> kerekitek 3000re
    Point a,b;
    for(int i = 0; i < numPoints; ++i){
        for (int j = i+1; j < numPoints; ++j) {
            int d = distance(points[i], points[j]);
            if( d < minDistance){
                minDistance = d;
                a = points[i], b = points[j];
            }
        }
    }

    a.print();
    b.print();
}

void farthestPoints(Point *points, int numPoints) {
    int minDistance=0;
    Point a,b;
    for(int i = 0; i < numPoints; ++i){
        for (int j = i+1; j < numPoints; ++j) {
            int d = distance(points[i], points[j]);
            if( d > minDistance){
                minDistance = d;
                a = points[i], b = points[j];
            }
        }
    }

    a.print();
    b.print();
}

void deletePoints(Point *points) {
    delete [] points;
    // free(points); // ?
}
