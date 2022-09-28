#include <iostream>
#include "Point.h"
#include "util.h"
using namespace std;

void test_distance();

int main(int argc, char** argv) {
    test_distance();
    return 0;
}

void test_distance(){
    Point p1(0,0);
    cout << "distance(p1,p1): " << distance(p1,p1) << endl;
}