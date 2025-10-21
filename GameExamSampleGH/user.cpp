//
// Created by denes on 2025. 10. 21..
//

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "user.h"

User::User() {
    this->username="";
}

User::User(const string &username) {
    this->username=username;
}

User::User(const User &other) {
    this->username=other.username;
    this->wishlist= other.wishlist;
}

User::User(User &&other) {
    this->username=move(other.username);
    this->wishlist= move(other.wishlist);
}

User &User::operator=(const User &other) {
    if(this!=&other){
        this->username=other.username;
        this->wishlist= other.wishlist;
    }
    return *this;
}

User &User::operator=(User &&other) {
    if(this!=&other){
        this->username=move(other.username);
        this->wishlist=move(other.wishlist);
    }
    return *this;
}

std::string User::getUsername() const {
    return this->username;
}

void User::addToWishlist(const Game &game) {
    auto it = std::find_if(wishlist.begin(), wishlist.end(), [&](const Game &f) {
        return f.getTitle() == game.getTitle();
    });
    if(it==this->wishlist.end()){
        this->wishlist.push_back(game);
    }
    else{
        throw invalid_argument("Mar szerepel a kivansaglistan.");
    }

}

void User::removeFromWishlist(const string &gameTitle) {
    auto it = std::find_if(wishlist.begin(), wishlist.end(), [&](const Game &f) {
        return f.getTitle() == gameTitle;
    });
    if(it==this->wishlist.end()){
        throw invalid_argument("Nincs benne.");
    }
    this->wishlist.erase(it);
}

void User::sortWishlistBy(SortOption option) {
    if(option==0){
        sort(this->wishlist.begin(), this->wishlist.end(), [](Game &g1, Game &g2){
            return g1.getTitle()<g2.getTitle();
        });
    }
    if(option==1){
        sort(this->wishlist.begin(), this->wishlist.end(), [](Game &g1, Game &g2){
            return g1.getPrice()<g2.getPrice();
        });
    }
}

std::ostream &operator<<(ostream &os, const User &user) {
    os<<user.username<<"'s wishlist: "<<endl;
    for(Game g:user.wishlist){
        cout<<g<<endl;
    }
    return os;
}

std::istream &operator>>(istream &is, User &user) {
    cout<<"Add meg a felhasznalonevet: ";
    is>>user.username;
    cout<<"Add meg hany jatekot szeretnel berakni: ";
    int n;
    is>>n;
    for (int i = 0; i < n; ++i) {
        Game g;
        is>>g;
        user.wishlist.push_back(g);
    }
    return is;
}






