//
// Created by ASUS on 2022. 12. 07..
//

#include "SettlementStatisticImpl.h"
#include <sstream>
#include <fstream>
#include <unordered_set>

int SettlementStatisticImpl::numSettlements() const {
    return data.size();
}

int SettlementStatisticImpl::numCounties() const {
   unordered_set<string> set;
   for( auto &item: this->data){
       set.insert(item.first);
   }
    return set.size();
}

int SettlementStatisticImpl::numSettlementsByCounty(const string &county) const {
    return 0;
}

vector<Settlement> SettlementStatisticImpl::findSettlementsByCounty(const string &county) const {
    return vector<Settlement>();
}

Settlement SettlementStatisticImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    return Settlement();
}

Settlement SettlementStatisticImpl::maxPopulationDensity() const {
    return Settlement();
}

Settlement SettlementStatisticImpl::minPopulationDensity() const {
    return Settlement();
}

vector<Settlement> SettlementStatisticImpl::findSettlementsByName(const string &name) {
    return vector<Settlement>();
}

SettlementStatisticImpl::SettlementStatisticImpl(const string &fileName) {
    ifstream input(fileName);
    if (!input){
        cerr << "File open error" << endl;
        exit(1);
    }

    string line;
    getline(input,line); // skip header
    while(getline(input,line)){
        stringstream ss(line);
        string name, county;
        int pop;
        getline(ss, name, ',');
        getline(ss, county, ',');
        ss >> pop;
        this->data.insert({county,Settlement(name,county,pop)});
    }
}
