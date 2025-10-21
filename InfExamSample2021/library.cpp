//
// Created by denes on 2025. 10. 21..
//

#include <algorithm>
#include "library.h"

using namespace std;
Library::Library(const std::string name) {
    this->name=name;
}
void Library::addBook(Book b){
    this->books.push_back(b);
}

void Library::printbooks() {
    for(Book b:this->books){
        cout<<b<<endl;
    }
}

const Book &Library::findBook(const string &searchTerm) {
    for(Book &b:this->books){
        if(b.getTitle().contains(searchTerm) || b.getAuthor().contains(searchTerm)){
            return b;
        }
    }
    throw invalid_argument("Nem talalhato.");
}

int Library::countBook(const string &searchTerm) {
    int nr=0;
    for(Book &b:this->books){
        if(b.getAuthor().contains(searchTerm)){
            nr++;
        }
    }
    return nr;
}

void Library::sortBooks() {
    std::sort(this->books.begin(), this->books.end(), [](Book &a, Book &b){
        if(a.getAuthor()==b.getAuthor()){
            return a.getYear()<b.getYear();
        }
        return a.getAuthor()<b.getAuthor();
    });
}

void Library::removeBook(Book b) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book &i) {
            return b.getTitle() == i.getTitle();
        });
        if(it==this->books.end()){
            throw invalid_argument("Nincs benne.");
        }
        this->books.erase(it);
        cout<<b<<" torolve";

}

