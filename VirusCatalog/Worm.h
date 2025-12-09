//
// Created by denes on 2025. 12. 09..
//

#ifndef VIRUSCATALOG_WORM_H
#define VIRUSCATALOG_WORM_H

#include "Malware.h"

class Worm : public Malware{
    string terjedesiMod;
public:
    void print(ostream& os) const override;
    Worm(string type, string name, int year, int lvl, string desc, string terjedesimod);
    string getterjedesiMod();
    friend ostream& operator <<(ostream& os, const Worm& what);
};
#endif //VIRUSCATALOG_WORM_H
