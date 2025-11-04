//
// Created by denes on 2025. 11. 04..
//

#include <algorithm>
#include <random>
#include "Shelter.h"

Shelter::Shelter(const string name) {
    this->name=name;
}

Shelter::Shelter(const Shelter &other) {
    this->name = other.name;
    this->dogs = other.dogs;
}

Shelter::Shelter(const Shelter &&other)  noexcept {
    this->name = move(other.name);
    this->dogs = move(other.dogs);
}

void operator+(Shelter &a, const Dog &b) {
    auto it =find_if(a.dogs.begin(), a.dogs.end(), [&](const Dog& d){
        return d.getId()==b.getId();
    });
    if(it==a.dogs.end()){
        a.dogs.push_back(b);
    }
    else{
        throw out_of_range("Mar benne van.");
    }
}

ostream &operator<<(ostream &os,const Shelter s) {
    os<<s.name<<"'s dogs: "<<endl;
    for(Dog d:s.dogs){
        cout<<d<<endl;
    }
    return os;
}

void operator-(Shelter &a, const int id) {
    auto it =find_if(a.dogs.begin(), a.dogs.end(), [&](const Dog& d){
        return d.getId()==id;
    });
    if(it==a.dogs.end()){
        throw out_of_range("Nincs benne.");
    }
    else{
        a.dogs.erase(it);
    }
}

Dog *Shelter::operator[](int index) {
    if(index>this->dogs.size() || index<0){
        throw out_of_range("Index out of range.");
    }
    else{
        return  &this->dogs.at(index);
    }
}

const Dog *Shelter::operator[](int index) const {
    if(index>this->dogs.size() || index<0){
        throw out_of_range("Index out of range.");
    }
    else{
        return  &this->dogs.at(index);
    }
}

Dog Shelter::adoptRandom() {
    random_device rd;
     std::mt19937 gen(rd());
     std::uniform_int_distribution<int>dist(0, this->dogs.size());
     int random_number=dist(gen);
     Dog d= this->dogs.at(random_number);
     this-d.getId();
    return d;
}


