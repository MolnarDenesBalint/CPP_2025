//
// Created by denes on 2025. 11. 04..
//
#include <string>
#include "Author.h"

using namespace std;
#ifndef EXAMSAMPLE2025B_BOOK_H
#define EXAMSAMPLE2025B_BOOK_H
class Book{
    string title;
    Author author;
    int pages;
    int year;
public:
    Book();
    Book(string title, Author author, int pages, int year );
    const string &getTitle() const;
    const Author &getAuthor() const;
    int getPages() const;
    int getYear() const;
    friend ostream& operator <<(ostream&os, Book& what);
    friend bool operator <(const Book& b1, const Book& b2);
};
#endif //EXAMSAMPLE2025B_BOOK_H
