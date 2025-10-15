//
// Created by denes on 2025. 10. 15..
//

#include <algorithm>
#include "user.h"
using namespace std;
User::User() {
    this->name="";
}

User::User(const std::string &name) {
    this->name=name;
}

User::User(const User &other) {
    this->name=other.name;
    this->itinerary=other.itinerary;
}

User::User(User &&other) {
    this->name=move(other.name);
    this->itinerary=move(other.itinerary);
}

User &User::operator=(const User &other) {
    if(this!=&other){
        this->name=other.name;
        this->itinerary=other.itinerary;
    }
    return *this;
}

User &User::operator=(User &&other) {
    if(this!=&other){
        this->name=move(other.name);
        this->itinerary=move(other.itinerary);
    }
    return *this;
}

std::string User::getName() const {
    return this->name;
}

void User::addToItinerary(const Flight &flight) {
    for(Flight f:this->itinerary){
        if(f==flight){
            throw invalid_argument("Mar benne van.");
        }
    }
    this->itinerary.push_back(flight);
}

void User::removeFromItinerary(const string &departure, const string &destination) {
    auto it = std::find_if(itinerary.begin(), itinerary.end(), [&](const Flight &f) {
        return f.getDeparture() == departure && f.getDestination() == destination;
    });
    if(it==this->itinerary.end()){
        throw invalid_argument("Nincs benne.");
    }
    this->itinerary.erase(it);
}

void User::sortItineraryByPopularity() {
    std::sort(this->itinerary.begin(), this->itinerary.end(), [](const Flight& a, const Flight& b){
        return a.getPopularity()-b.getPopularity();
    });
}

void User::removeUnpopularFlights(double minPopularity) {
    itinerary.erase(std::remove_if(itinerary.begin(), itinerary.end(), [minPopularity](const Flight &f) {
        return f.getPopularity() < minPopularity;
    }), itinerary.end());
}

std::ostream &operator<<(ostream &os, const User &user) {
    os<<user.name<<": ";
    for(Flight f:user.itinerary){
        cout<<f<<endl;
    }
    return os;
}

std::istream &operator>>(istream &is, User &user) {
    int n;
    Flight f;
    is>>user.name>>n;
    for (int i = 0; i < n; ++i) {
        cin>>f;
        user.addToItinerary(f);
    }
    return is;
}





