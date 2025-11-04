//
// Created by denes on 2025. 11. 04..
//
#include <string>
#include <iostream>

using namespace std;
#ifndef EXAMSAMPLE2025B_AUTHOR_H
#define EXAMSAMPLE2025B_AUTHOR_H
class Author{
    string name;
    int birthyear;
public:
    Author();
    Author(string name, int year);
    Author(const Author&other);
    Author(Author&&other) noexcept ;
    const string &getName() const;
    int getBirthyear() const;
    friend ostream& operator<<(ostream&os, const Author &what);
    Author& operator=(const Author& other);
   Author& operator=(Author&& other) noexcept;
};
#endif //EXAMSAMPLE2025B_AUTHOR_H
