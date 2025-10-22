//
// Created by denes on 2025. 10. 22..
//

#ifndef LAB6_USER_H
#define LAB6_USER_H

#include <string>
#include <map>

using namespace std;
class User{
    int id;
    static int count;
    string name;
    map<int, double>results;
public:
    User(const string &name);
    void addResult(const int id, const double result);
    void printresults();
};

#endif //LAB6_USER_H
