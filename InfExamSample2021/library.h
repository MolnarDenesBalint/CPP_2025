//
// Created by denes on 2025. 10. 21..
//

#ifndef INFEXAMSAMPLE2021_LIBRARY_H
#define INFEXAMSAMPLE2021_LIBRARY_H
#include <iostream>
#include <string>
#include <vector>
#include "book.h"
using namespace std;
class Library{
    string name;
    vector<Book> books;
public:
    Library(const string name);
    void addBook(Book b);
    void printbooks();
    const Book& findBook(const string& searchTerm);
    int countBook(const string& searchTerm);
    void sortBooks();
    void removeBook(Book b);
};
#endif //INFEXAMSAMPLE2021_LIBRARY_H
