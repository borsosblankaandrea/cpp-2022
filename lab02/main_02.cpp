#include <iostream>
#include <fstream>
#include <algorithm>
#include "Point.h"
#include "util.h"
using namespace std;

void test_distance();
void test_print();
void test_isSquare();
void comparePoints(const Point &p1, const Point &p2);

int main(int argc, char** argv) {

    Point points[] {{10,10}, {1,0}, {0,1}, {1,1}};
    for(auto& point: points){
        cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }

    cout << endl;
    ///sort(points, points +4, comparePoints);

    for(auto& point: points){
        cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }
//    ifstream ifs("points.txt");
//    if(!ifs) {
//        cout << "File open error" << endl;
//        return -1;
//    }
//
//    int x, y;
//    ifs >> x >> y;
//    cout<< "x: " << x << "y: " << endl;

    //test_print();
    //test_isSquare();


    return 0;
}

void test_distance(){
    Point p1(0,0);
    cout << "distance(p1,p1): " << distance(p1,p1) << endl;
    cout << "distance(p1,Point(3,4)): " << distance(p1, Point(3,4)) << endl;
}

void test_print(){
    Point p(2,4);
    p.print();
}

void test_isSquare(){
    Point a(1,1), b(1,2), c(2,2), d(2,1);
    if(isSquare(a,b,c,d)) cout << "It is a square!" << endl;
    else cout << "It is not a square!" << endl;

}

void comparePoints(const Point &p1, const Point &p2){

}