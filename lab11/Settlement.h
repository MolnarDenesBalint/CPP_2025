//
// Created by denes on 2025. 11. 26..
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;
#ifndef LAB11_SETTLEMENT_H
#define LAB11_SETTLEMENT_H
class Settlement{
    string name = "";
    string county = "";
    int population = 0;
public:
    const string &getName() const;

    const string &getCounty() const;

    int getPopulation() const;

    Settlement(const string &name, const string &county, int population);

    Settlement();

    void setName(const string &name);

    void setPopulation(int population);

    void setCounty(const string &county);
    friend ostream& operator<<(ostream& os, Settlement &what);
};
#endif //LAB11_SETTLEMENT_H
