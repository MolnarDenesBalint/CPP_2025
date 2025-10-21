//
// Created by denes on 2025. 10. 21..
//

#include "book.h"

const string &Book::getAuthor() const {
    return author;
}

const string &Book::getTitle() const {
    return title;
}

int Book::getYear() const {
    return year;
}

int Book::getPages() const {
    return pages;
}

Book::Book(const string author, const string title, const int year, const int pages) {
    this->author=author;
    this->title=title;
    this->pages=pages;
    this->year=year;
}

void Book::print(ostream &os) const{
    os<<this->author<<" "<< this->title <<" - "<<this->year<<" Page Number:"<<this->pages;
}

ostream &operator<<(ostream &os, const Book &book) {
    book.print(os);
    return os;
}
