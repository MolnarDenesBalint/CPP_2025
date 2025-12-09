//
// Created by denes on 2025. 12. 09..
//

#include <algorithm>
#include "VirusCatalog.h"

void VirusCatalog::addMalware(Malware* m) {
    auto it = find_if(items.begin(), items.end(),[&m](Malware* t){return m->getName()==t->getName();});
    if(it==items.end()){
        items.push_back(m);
    }
    else{
        throw out_of_range ("Mar benne van");
    }
}

void VirusCatalog::printCatalog() {
    if(items.empty()){
        cout<<"A katalogus ures."<<endl;
    }
    else{
        for(Malware* m :items){
            cout<<*m<<endl;

        }
    }
}

Malware *VirusCatalog::findByName(string name) {
    for(Malware* m:items){
        if(m->getName()==name){
            return m;
        }
    }
        cout<<"Nincs benne!";
        return nullptr;
}

vector<Malware *> VirusCatalog::findByType(string type) {
    vector<Malware *>result;
    for(Malware* m:items){
        if(m->getType()[0]==type[0]){
            result.push_back(m);
        }
    }
    return result;
}

void VirusCatalog::sortByThreatLevelDesc() {
    sort(items.begin(), items.end(), [](const Malware *a, const Malware*b){return a->getLvl()>b->getLvl();});
}
