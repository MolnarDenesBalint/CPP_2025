//
// Created by denes on 2025. 10. 15..
//

#include "flight.h"
using namespace std;
Flight::Flight(const std::string &departure, const std::string &destination, double price, double popularity) {
    this->departure=departure;
    this->destination=destination;
    this->price=price;
    this->popularity=popularity;
}

Flight::Flight(const Flight &other) {
    this->departure=other.departure;
    this->destination=other.destination;
    this->price=other.price;
    this->popularity=other.popularity;

}

Flight::Flight() {
    this->departure="";
    this->destination="";
    this->price=0;
    this->popularity=0;
}

Flight::Flight(Flight &&other) {
    this->departure=move(other.departure);
    this->destination=move(other.destination);
    this->price=other.price;
    this->popularity=other.popularity;
    other.price=0;
    other.popularity=0;
}

Flight &Flight::operator=(const Flight &other) {
    if(*this!=other){
        this->departure=other.departure;
        this->destination=other.destination;
        this->price=other.price;
        this->popularity=other.popularity;
    }
    return *this;
}

Flight &Flight::operator=(Flight &&other) {
    if(*this!=other){
        this->departure=move(other.departure);
        this->destination=move(other.destination);
        this->price=other.price;
        this->popularity=other.popularity;
        other.price=0;
        other.popularity=0;
    }
    return *this;
}

std::string Flight::getDeparture() const {
    return this->departure;
}

std::string Flight::getDestination() const {
    return this->destination;
}

double Flight::getPrice() const {
    return this->price;
}

double Flight::getPopularity() const {
    return this->popularity;
}

bool Flight::operator==(const Flight &other) const {
    if(this->departure!=other.departure || this->destination!=other.destination || this->price!=other.price || this->popularity!=other.popularity){
        return false;
    }
    return true;
}

std::ostream &operator<<(ostream &os, const Flight &flight) {
    os<<flight.departure<<": "<<flight.destination<<"   Price: "<<flight.price<<"   Popularity: "<<flight.popularity<<endl;
    return os;
}

std::istream &operator>>(istream &is, Flight &flight) {
    is>>flight.departure>>flight.destination>>flight.price>>flight.popularity;
    return is;
}


