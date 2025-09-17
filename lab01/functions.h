//
// Created by denes on 2025. 09. 17..
//

#ifndef CPP_2024_FUNCTIONS_H
#define CPP_2024_FUNCTIONS_H
#include <string>
#include <utility>
using namespace std;
int countbits (int a);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
int cmp(const void * p, const void * arg);
std::pair<double, double> max2(double array[], int numElements);
int countWords(std::string text);
int sumwords(std::string text);
string code(string text);
string capitalize(string text);
void readfile(string filename);
#endif //CPP_2024_FUNCTIONS_H