//
// Created by denes on 2025. 12. 09..
//

#include "Ransomware.h"

Ransomware::Ransomware(string type, string name, int year, int lvl, string desc, int valsagdijUSD) {
    this->Type=type;
    this->name=name;
    this->year=year;
    this->lvl=lvl;
    this->desc=desc;
    this->valsagDijUSD=valsagdijUSD;
}

int Ransomware::getvalsagDijUSD() {
    return valsagDijUSD;
}

ostream &operator<<(ostream &os, const Ransomware& what) {
    what.print(os);
    return os;
}

void Ransomware::print(ostream &os) const {
    os<<Type<<" "<<name<<" "<<year<<" "<<lvl<<endl<<desc<<endl<<valsagDijUSD<<endl;

}


