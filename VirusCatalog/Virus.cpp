//
// Created by denes on 2025. 12. 09..
//

#include "Virus.h"
#include "iostream"

Virus::Virus(string type, string name, int year, int lvl, string desc, bool halozatonterjed) {
    this->Type=type;
    this->name=name;
    this->year=year;
    this->lvl=lvl;
    this->desc=desc;
    this->halozatonTerjed=halozatonterjed;
}

bool Virus::getHalozatonTerjed() const {
    return halozatonTerjed;
}

ostream &operator<<(ostream &os, const Virus& what) {
    what.print(os);
    return os;
}

void Virus::print(ostream &os) const{
    os<<Type<<" "<<name<<" "<<year<<" "<<lvl<<endl<<desc<<endl<<halozatonTerjed<<endl;

}
