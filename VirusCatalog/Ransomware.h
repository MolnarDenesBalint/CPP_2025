//
// Created by denes on 2025. 12. 09..
//

#ifndef VIRUSCATALOG_RANSOMWARE_H
#define VIRUSCATALOG_RANSOMWARE_H

#include "Malware.h"

class Ransomware : public Malware{
    int valsagDijUSD;
public:
    Ransomware(string type, string name, int year, int lvl, string desc, int valsagdijUSD);
    int getvalsagDijUSD();
    friend ostream& operator <<(ostream& os, const Ransomware& what);
    void print(ostream &os) const  override;
};
#endif //VIRUSCATALOG_RANSOMWARE_H
