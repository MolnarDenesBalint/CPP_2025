//
// Created by denes on 2025. 12. 09..
//

#ifndef VIRUSCATALOG_VIRUS_H
#define VIRUSCATALOG_VIRUS_H

#include "Malware.h"

class Virus : public Malware{
    bool halozatonTerjed;
public:
    Virus(string type, string name, int year, int lvl, string desc, bool halozatonterjed);
    bool getHalozatonTerjed() const;
    friend ostream& operator <<(ostream& os, const Virus& what);
    void print(ostream &os) const override;
};
#endif //VIRUSCATALOG_VIRUS_H
