//
// Created by denes on 2025. 11. 04..
//

#include "Author.h"

Author::Author() {
    this->name="";
    this->birthyear=0;
}

Author::Author(const string name, const int year) {
    this->name=name;
    this->birthyear=year;
}

Author::Author(const Author &other) {
    this->name=other.name;
    this->birthyear=other.birthyear;

}

Author::Author(Author &&other)  noexcept {
    this->name=move(other.name);
    this->birthyear=other.birthyear;
    other.birthyear=0;
}

const string &Author::getName() const {
    return name;
}

int Author::getBirthyear() const {
    return birthyear;
}

ostream &operator<<(ostream &os, const Author &what) {
    os<<what.name<<" ("<<what.birthyear<<")";
    return os;
}

Author &Author::operator=(const Author &other) {
    if(this!=&other){
        this->name=other.name;
        this->birthyear=other.birthyear;
    }
    return *this;
}

Author &Author::operator=(Author &&other) noexcept {
    if(this!=&other){
        this->name=move(other.name);
        this->birthyear=other.birthyear;
        other.birthyear=0;
    }
    return *this;
}

