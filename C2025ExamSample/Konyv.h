//
// Created by denes on 2025. 12. 09..
//

#ifndef C2025EXAMSAMPLE_KONYV_H
#define C2025EXAMSAMPLE_KONYV_H

#include <string>

using namespace std;
class Konyv{
    string isbn;
    string cim;
    string szerzo;
    int ev;
public:
    Konyv()=default;
    Konyv(const string &isbn, const string &cim, const string &szerzo, int ev);
    ~Konyv()=default;

    const string &getIsbn() const;

    const string &getCim() const;

    const string &getSzerzo() const;

    int getEv() const;
    friend ostream& operator<<(ostream&os, Konyv &what);
};
#endif //C2025EXAMSAMPLE_KONYV_H
