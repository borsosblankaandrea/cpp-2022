#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>

#include "Point.h"
#include "PointsSet.h"
#define MAX 1000
using namespace std;

int main() {

    int n = 2;
    cout<< fixed;
    for( int i = 0; i<4; ++i ){
        PointSet pSet( n );
        cout<<i << ".\n";
        //cout<<i<<". Pontok\tMinTav\t MaxTav\t#kulonbozotavolsagok"<<endl;
        cout<< "Pontok: " <<n<<endl;
        cout<< "MinTav: " <<setprecision(2)<<pSet.minDistance()<<endl;
        cout<< "MaxTav: " <<setprecision(2)<<pSet.maxDistance()<<endl;
        cout<< "#kulonbozotavolsagok: " << pSet.numDistances()<<endl;
        cout<<"Pontok: "<< endl;
        pSet.printPoints();
        cout<<"Tavolsagok rendezve: ";
        pSet.sortDistances();
        pSet.printDistances();
        cout<<endl<<endl;
        //cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        n = n << 1;
    }
    return 0;
}