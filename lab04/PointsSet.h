//
// Created by ASUS on 2022. 10. 12..
//

#ifndef CPP_2022_POINTSSET_H
#define CPP_2022_POINTSSET_H
#define M 2000

#include "Point.h"
#include <vector>

using namespace std;
class PointSet{
    //különböző pontok
    vector<Point> points;
    //különböző pontok száma
    int n;
    //pontok kozotti tavolsagok
    vector<double> distances;
    //segédfüggvény, amely feltölti a distances tömböt
    void computeDistances();
public:
    //konstruktor: előállítja a points tömböt
    //kiszámítja a pontok közötti távolságokat (tavolsagok tömb),
    PointSet( int n = 100 );
    //maximum kiválasztás a tavolsag tömbből
    double maxDistance() const;
    //minimum kiválasztás a tavolsag tömbből
    double minDistance() const;
    //összesen hány távolság értelmezhető n különböző pont között
    int numDistances() const;
    //a pontok tároló kiíratása
    void printPoints() const;
    //a tavolsagok tároló kiíratása
    void printDistances() const;
    //növekvő sorrendbe rendezi a pontokat x koordináta szerint
    void sortPointsX();
    //u. a. y koordináta szerint
    void sortPointsY();
    //a tavolsagok tároló rendezése
    void sortDistances();
    //hány darab különböző távolságot tartalmaz a tavolsagok tömb
    int numDistinctDistances();
};


#endif //CPP_2022_POINTSSET_H
