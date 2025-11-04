//
// Created by denes on 2025. 11. 04..
//

#include "Dog.h"
int Dog::count=0;
Dog::Dog( const string &name, const string &type, const int age) {
    this->name=name;
    this->age=age;
    this->type=type;
    this->id=++count;
}

Dog::Dog(const Dog &other) {
    this->id=other.id;
    this->name=other.name;
    this->age=other.age;
    this->type=other.type;
}

Dog::Dog(Dog &&other) noexcept {
    this->id=other.id;
    other.id=0;
    this->name=other.name;
    other.name.clear();
    this->age=other.age;
    other.age=0;
    other.type.clear();
}

ostream &operator<<(ostream &os, const Dog &what) {
    os<<what.id<<". "<<what.name<<endl<<"\tKor: "<<what.age<<endl<<"\tFajta: "<<what.type;
    return os;
}

Dog &Dog::operator=(const Dog &other) {
    if(this!=&other){
        this->id=other.id;
        this->name=other.name;
        this->age=other.age;
        this->type=other.type;
    }
    return *this;
}

Dog &Dog::operator=(Dog &&other) {
    if(this!=&other){
        this->id=other.id;
        other.id=0;
        this->name=other.name;
        other.name.clear();
        this->age=other.age;
        other.age=0;
        other.type.clear();
    }
    return *this;
}

int Dog::getId() const {
    return id;
}

int Dog::getAge() const {
    return age;
}

const string &Dog::getName() const {
    return name;
}

const string &Dog::getType() const {
    return type;
}

Dog::Dog() {
    this->name="";
    this->age=0;
    this->type="";
    this->id=++count;

}

