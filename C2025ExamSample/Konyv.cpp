//
// Created by denes on 2025. 12. 09..
//

#include "Konyv.h"
#include <iostream>

Konyv::Konyv(const string &isbn, const string &cim, const string &szerzo, int ev) {
    this->isbn=isbn;
    this->cim=cim;
    this->szerzo=szerzo;
    this->ev=ev;
}

const string &Konyv::getIsbn() const {
    return isbn;
}

const string &Konyv::getCim() const {
    return cim;
}

const string &Konyv::getSzerzo() const {
    return szerzo;
}

int Konyv::getEv() const {
    return ev;
}

ostream &operator<<(ostream &os, Konyv &what) {
    os<<what.isbn<<": "<<what.cim<<" - "<<what.szerzo<<" : "<<what.ev;
    return os;
}



