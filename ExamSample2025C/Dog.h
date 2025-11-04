//
// Created by denes on 2025. 11. 04..
//

#ifndef EXAMSAMPLE2025C_DOG_H
#define EXAMSAMPLE2025C_DOG_H

#include <string>
#include<iostream>

using namespace std;
class Dog{
     int id;
     int age;
     string name;
     string type;
     static int count;
public:
    Dog();
    Dog( const string &name, const string &type, int age);
    Dog(const Dog &other);
    Dog(Dog &&other) noexcept ;
    friend ostream& operator<<(ostream &os, const Dog&what );
    Dog& operator=(const Dog &other);
    Dog& operator=(Dog &&other);

    int getId() const;

    int getAge() const;

    const string &getName() const;

    const string &getType() const;
};
#endif //EXAMSAMPLE2025C_DOG_H
