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
        if(distance(a,c) == distance(b,d)){
            return 1;
        }
    }
    return 0;
}
