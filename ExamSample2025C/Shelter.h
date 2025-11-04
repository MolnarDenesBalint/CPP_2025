//
// Created by denes on 2025. 11. 04..
//

#ifndef EXAMSAMPLE2025C_SHELTER_H
#define EXAMSAMPLE2025C_SHELTER_H

#include <vector>
#include "Dog.h"
using namespace std;
class Shelter{
    string name;
    vector<Dog>dogs;
public:
    Shelter(string name);
    Shelter(const Shelter &other);
    Shelter(const Shelter &&other) noexcept;
    friend void operator +(Shelter &a, const Dog &b);
    friend void operator -(Shelter &a, const int id);
    friend ostream& operator <<(ostream&os,const Shelter s);
    Dog* operator[](int index);
    const Dog* operator[](int index) const;
    Dog adoptRandom();
};
#endif //EXAMSAMPLE2025C_SHELTER_H
