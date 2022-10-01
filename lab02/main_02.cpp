#include <iostream>
#include <fstream>
#include <algorithm>
#include "Point.h"
#include "util.h"

using namespace std;

void test_distance();
void test_print(Point p);
void testIsSquare(const char * filename);
void test_cereate();
void comparePoints(const Point &p1, const Point &p2);

int main(int argc, char** argv) {

//    Point points[] {{10,10}, {1,0}, {0,1}, {1,1}};
//    for(auto& point: points){
//        cout << "(" << point.getX() << ", " << point.getY() << ") ";
//    }
//
//    cout << endl;
//    ///sort(points, points +4, comparePoints);
//
//    for(auto& point: points){
//        cout << "(" << point.getX() << ", " << point.getY() << ") ";
//    }


    //testIsSquare("points.txt");
    test_cereate();

    return 0;
}

void test_distance(){
    Point p1(0,0);
    cout << "distance(p1,p1): " << distance(p1,p1) << endl;
    cout << "distance(p1,Point(3,4)): " << distance(p1, Point(3,4)) << endl;
}

void test_print(Point p){
    p.print();
}

void testIsSquare(const char * filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cout << "File open error" << endl;
        exit(0);
    }

    while(!ifs.eof()) {
        int x, y;
        ifs >> x >> y;
        Point a(x, y);

        ifs >> x >> y;
        Point b(x, y);

        ifs >> x >> y;
        Point c(x, y);

        ifs >> x >> y;
        Point d(x, y);

        if (isSquare(a, b, c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

void test_cereate(){
    int n;
    cout << "Number of points:";
    cin >> n;
    //cout << createArray(n) << endl;
    Point *points = createArray(n);
    printArray(points,n);

    cout << endl << "Closest points: " << endl;
    closestPoints(points, n);

    cout << endl << "Farthest points: " << endl;
    farthestPoints(points, n);


}


void comparePoints(const Point &p1, const Point &p2){

}