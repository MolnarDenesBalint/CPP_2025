//
// Created by denes on 2025. 10. 21..
//

#ifndef INFEXAMSAMPLE2021_BOOK_H
#define INFEXAMSAMPLE2021_BOOK_H
#include <iostream>
#include <string>

using namespace std;
class Book{
     string author;
    string title;
    int year;
    int pages;
public:
    Book(const string author, const string title, const int year, const int pages);
    const string &getAuthor() const;
    const string &getTitle() const;
    int getYear() const;
    int getPages() const;
    void print(ostream &os) const;
    friend ostream &operator<<(ostream &os, const Book &book);
};
#endif //INFEXAMSAMPLE2021_BOOK_H
