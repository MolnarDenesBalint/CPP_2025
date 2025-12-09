//
// Created by denes on 2025. 12. 09..
//

#ifndef C2025EXAMSAMPLE_KONYVTARISTATISZTIKA_H
#define C2025EXAMSAMPLE_KONYVTARISTATISZTIKA_H

#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include "Konyv.h"

using namespace std;



class KonyvtariStatisztika{
    map<string, Konyv>konyvek;
    map<string, vector<string>>kolcsonzesek;
    unordered_map<string, int>isbngyakorisag;
public:
    KonyvtariStatisztika()=default;
    void konyvekBetoltese(string filename);
    void printKonyvek();
    void kolcsonzesekBetoltese(string filename);
    void printKolcsonzesek();
    void printisbngyakorisag();
    void legnepszerubbKonyv();
    void olvasoKolcsonzesei(string nev);
    void szerzoStatisztika();
    void reszletesStatisztika();
};
#endif //C2025EXAMSAMPLE_KONYVTARISTATISZTIKA_H
