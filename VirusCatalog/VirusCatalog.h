//
// Created by denes on 2025. 12. 09..
//

#ifndef VIRUSCATALOG_VIRUSCATALOG_H
#define VIRUSCATALOG_VIRUSCATALOG_H

#include <vector>
#include "Malware.h"

class VirusCatalog{
    vector<Malware*> items;
public:
    void addMalware(Malware* m);
    void printCatalog();
    Malware* findByName(string name);
    vector<Malware*>findByType(string type);
    void sortByThreatLevelDesc();
};
#endif //VIRUSCATALOG_VIRUSCATALOG_H
