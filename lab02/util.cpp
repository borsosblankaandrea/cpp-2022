
#ifndef UTIL_H
#define UTIL_H

#include "util.h"

double distance(const Point& a, const Point& b){
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY, 2));
}