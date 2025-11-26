//
// Created by denes on 2025. 11. 26..
//

#include "Settlement.h"

const string &Settlement::getName() const {
    return name;
}

const string &Settlement::getCounty() const {
    return county;
}

int Settlement::getPopulation() const {
    return population;
}

Settlement::Settlement(const string &name, const string &county, int population) : name(name), county(county),
                                                                                   population(population) {}

void Settlement::setName(const string &name) {
    Settlement::name = name;
}

void Settlement::setPopulation(int population) {
    Settlement::population = population;
}

void Settlement::setCounty(const string &county) {
    Settlement::county = county;
}

ostream &operator<<(ostream &os, Settlement &what) {
    os<<what.name<<" - "<<what.county<<": "<<what.population<<endl;
    return os;
}

Settlement::Settlement() {};
