//
// Created by denes on 2025. 11. 04..
//

#include <algorithm>
#include <fstream>
#include "Library.h"

Library::Library() =default;


void Library::addBook(const Book &b) {
    books.push_back(b);
}

void Library::displayAll() {
    for(Book b: books){
        cout<<b;
    }
}

void Library::sotrByTitle() {
    sort(books.begin(), books.end(), [](const Book &a, const Book &b){return a < b;});
}

void Library::sortByPages() {
    sort(books.begin(), books.end(), [](const Book &a, const Book &b)
    {return a.getPages()<b.getPages();});
}

void Library::sortBYAuthorAndYear() {
    sort(books.begin(), books.end(), [](const Book &a, const Book &b)
    {if(a.getAuthor().getName()==b.getAuthor().getName()){
        return a.getYear()<b.getYear();
    }
        return a.getAuthor().getName()<b.getAuthor().getName();
    });
}

vector<Book> Library::searchByTitle(const string &keyword) {
    vector<Book>result;
    for(Book b:books){
        if(b.getTitle().contains(keyword)){
            result.push_back(b);
        }
    }
    return result;
}

bool Library::loadFromFile(const string &filename) {
    ifstream f(filename);
    if (!f.is_open()){return false;}
    while(!f.eof()){
        string cim;
        getline(f, cim);
        string koltoneve;
        getline(f, koltoneve);
        int koltoev;
        f>>koltoev;
        f.ignore();
        int page;
        f>>page;
        f.ignore();
        int ev;
        f>>ev;
        f.ignore();
        Author a(koltoneve, koltoev);
        Book b(cim, a, page, ev);
        books.push_back(b);
    }
    return true;
}
