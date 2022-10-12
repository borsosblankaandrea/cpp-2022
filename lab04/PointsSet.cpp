//
// Created by ASUS on 2022. 10. 12..
//

#include <iostream>
#include <random>
#include <algorithm>
#include "PointsSet.h"

using namespace std;

PointSet::PointSet(int n) {
    this->n = n;

    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(1, 2000);

    while(points.size() < n){
        int x = distrib(gen), y = distrib(gen);
        points.emplace_back(x,y);
    }

    distances.reserve(n*(n-1)/2);
    computeDistances();

}

void PointSet::computeDistances() {
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            distances.emplace_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    //hany kulonbozo tavolsag van ?
}

void PointSet::printPoints() const {
    for (int i = 0; i < this->n; ++i) {
        cout << "[ " << points[i].getX() << ' ' << points[i].getY() << " ]" << endl;
    }
}

void PointSet::printDistances() const {
    for (int i = 0; i < distances.size(); ++i) {
        cout << distances[i] << ' ';
    }
}






