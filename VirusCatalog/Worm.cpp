//
// Created by denes on 2025. 12. 09..
//

#include "Worm.h"

Worm::Worm(string type, string name, int year, int lvl, string desc, string terjedesimod) {
    this->Type=type;
    this->name=name;
    this->year=year;
    this->lvl=lvl;
    this->desc=desc;
    this->terjedesiMod=terjedesimod;
}

string Worm::getterjedesiMod() {
    return terjedesiMod;
}

ostream &operator<<(ostream &os, const Worm& what) {
    what.print(os);
    return os;
}

void Worm::print(ostream &os) const {
    os<<Type<<" "<<name<<" "<<year<<" "<<lvl<<endl<<desc<<endl<<terjedesiMod<<endl;
}
