//
// Created by denes on 2025. 11. 26..
//

#include <fstream>
#include <sstream>
#include <set>
#include "SettlementStatisticsImpl.h"

int SettlementStatisticsImpl::numSettlements() const {
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    set<string>codes;
    for(auto &a : settlements){
        codes.insert(a.first);
    }
    return codes.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    int count=0;
    for(auto &a : settlements){
        if(a.first==county){count++;}
    }
    return count;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> result;
    for(auto &a : settlements){
        if(a.first==county){result.push_back(a.second);}
    }
    return result;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for(auto &a : settlements){
        if(a.first==county  && a.second.getName()==name){return a.second;}
    }
    throw out_of_range("nincs benne");
}

Settlement SettlementStatisticsImpl::maxPopulationBySettlement() const {
    int max=0;
    Settlement maxs;
    for(auto &a : settlements){
        if(a.second.getPopulation()>max){maxs=a.second; max=a.second.getPopulation();}
    }
    return maxs;
}

Settlement SettlementStatisticsImpl::minPopulationBySettlement() const {
    int min=INT_MAX;
    Settlement mins;
    for(auto &a : settlements){
        if(a.second.getPopulation()<min && a.second.getPopulation()!=0){mins=a.second; min=a.second.getPopulation();}
    }
    return mins;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> result;
    for(auto &a : settlements){
        if(a.second.getName()==name){result.push_back(a.second);}
    }
    return result;
}

SettlementStatisticsImpl::SettlementStatisticsImpl(string filename) {
    ifstream f(filename);
    if(!f.is_open()){cerr<<"Error"<<endl;return;}
    string temp;
    getline(f, temp);
    while(getline(f, temp)){
        stringstream ss(temp);
        string name, code, p;
        int popularity;
        getline(ss, name, ',');
        getline(ss, code, ',');
        getline(ss, p);
        if(p.empty()){
            popularity=0;
        }
        else{
            popularity=stoi(p);
        }

        Settlement temps (name, code, popularity);
        settlements.insert({code, temps});
    }
}
