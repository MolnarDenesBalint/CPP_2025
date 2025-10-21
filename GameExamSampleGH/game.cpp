//
// Created by denes on 2025. 10. 21..
//

#include "game.h"
#include <iostream>

Game::Game() {
    this->title="";
    this->price=0;
}

Game::Game(const string &title, double price) {
    this->title=title;
    this->price=price;
}

Game::Game(const Game &other) {
    this->title=other.title;
    this->price=other.price;
}

Game::Game(Game &&other) {
    this->title=other.title;
    this->price=other.price;
    other.title.clear();
    other.price=0;
}

Game &Game::operator=(const Game &other) {
    if(this!=&other){
        this->title=other.title;
        this->price=other.price;
    }
    return *this;
}

Game &Game::operator=(Game &&other) {
    if(this!=&other){
        this->title=other.title;
        this->price=other.price;
        other.title.clear();
        other.price=0;
    }
    return *this;
}

std::string Game::getTitle() const {
    return this->title;
}

double Game::getPrice() const {
    return this->price;
}

bool Game::operator==(const Game &other) {
    return this->title==other.title;
}

std::ostream &operator<<(ostream &os, const Game &game) {
    os<<game.title<<" "<<game.price<<endl;
    return os;
}

std::istream &operator>>(istream &is, Game &game) {
    cout<<"Add meg a jatek nevet:";
    is>>game.title;
    cout<<"Add meg a "<<game.title<<" jatek arat:";
    is>>game.price;
    return is;
}


