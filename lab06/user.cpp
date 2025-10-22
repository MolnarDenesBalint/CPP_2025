//
// Created by denes on 2025. 10. 22..
//

#include <iostream>
#include "user.h"
int User::count=0;
User::User(const string &name) {
    this->id=count;
    count++;
    this->name=name;
}

void User::addResult(const int id, const double result) {
    this->results.insert({id, result});
}

void User::printresults() {
    for(const auto &i:results){
        cout<<i.first<<" : "<<i.second;
    }
}
