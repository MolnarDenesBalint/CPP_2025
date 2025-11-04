//
// Created by denes on 2025. 11. 04..
//

#ifndef EXAMSAMPLE2025B_LIBRARY_H
#define EXAMSAMPLE2025B_LIBRARY_H

#include <vector>
#include "Book.h"
using namespace std;
class Library{
    vector<Book>books;
public:
    Library();
    void addBook(const Book& b);
    void displayAll();
    void sotrByTitle();
    void sortByPages();
    void sortBYAuthorAndYear();
    vector<Book> searchByTitle(const string& keyword);
    bool loadFromFile(const string& filename);
};
#endif //EXAMSAMPLE2025B_LIBRARY_H
