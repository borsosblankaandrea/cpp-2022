//
// Created by ASUS on 2022. 10. 12..
//

#include <valarray>
#include "Point.h"

int Point::counter{0};

Point::Point(int x, int y) {
    if (x >= 0 && x <= M && y >= 0 && y <= M){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
    counter++;
}

int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(point.getX() - this->x, 2) + pow(point.getY() - this->y, 2));
}

Point::Point(const Point &point) {
    this->x = point.x;
    this->y = point.y;
    counter++;
}





