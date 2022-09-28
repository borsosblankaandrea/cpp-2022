//
// Created by ASUS on 2022. 09. 28..
//

#include <cmath>
#include "util.h"

double distance(const Point& a, const Point& b){
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}
