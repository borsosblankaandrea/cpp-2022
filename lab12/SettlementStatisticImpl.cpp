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
    int counter = 0;
    for( auto &item: this->data){
        if(item.second.getCounty() == county) counter++;
    }

    return counter;
}

vector<Settlement> SettlementStatisticImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> vector1;
    for( auto &item: this->data){
        if(item.second.getCounty() == county){
            vector1.emplace_back(item.second);
        }
    }

    return vector1;
}

Settlement SettlementStatisticImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for( auto &item: this->data){
        if(item.second.getCounty() == county){
            if(item.second.getName() == name){
                return item.second;
            }
        }
    }
}

Settlement SettlementStatisticImpl::maxPopulationDensity() const {
    Settlement maxi;
    maxi.setPopulation(INT_MIN);
    for( auto &item: this->data){
        if(item.second.getPopulation() > maxi.getPopulation()){
            maxi = item.second;
        }
    }

    return maxi;
}

Settlement SettlementStatisticImpl::minPopulationDensity() const {
    Settlement mini;
    mini.setPopulation(INT_MAX);
    for( auto &item: this->data){
        if(item.second.getPopulation() < mini.getPopulation()){
            mini = item.second;
        }
    }

    return mini;
}

vector<Settlement> SettlementStatisticImpl::findSettlementsByName(const string &name) {
    vector<Settlement> vector1;
    for( auto &item: this->data){
        if(item.second.getName() == name){
            vector1.emplace_back(item.second);
        }
    }

    return vector1;
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
