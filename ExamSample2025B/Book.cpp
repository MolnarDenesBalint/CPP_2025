//
// Created by denes on 2025. 11. 04..
//

#include "Book.h"

Book::Book() {
    this->title="";
    this->pages=0;
    this->year=0;
    this->author=Author();
}

Book::Book(string title, Author author, int pages, int year) {
    this->author=author;
    this->year=year;
    this->title=title;
    this->pages=pages;
}


const string &Book::getTitle() const {
    return title;
}

const Author &Book::getAuthor() const {
    return author;
}

int Book::getPages() const {
    return pages;
}

int Book::getYear() const {
    return year;
}

ostream &operator<<(ostream &os, Book &what) {
    os<<"'"<<what.title<<"', by "<<what.author<<", "<<what.pages<<" pages, published "<<what.year<<endl;
    return os;
}

bool operator < (const Book &b1, const Book &b2) {
    return b1.getTitle()<b2.getTitle();
}

