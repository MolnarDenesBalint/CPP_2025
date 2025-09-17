//
// Created by denes on 2025. 09. 17..
//

#include "functions.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>

int countbits (int a) {
    int n=0;
    while (a) {
        if (a%2==1) {
            n++;
        }
        a>>=1;
    }
    return n;
}
bool setBit(int& number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    number |= (1 << order);
    return true;
}

double mean(double array[], int numElements) {
    double sum = 0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    if (sum!=0) {
        return sum/numElements;
    }
    return NAN;
}
double stddev(double array[], int numElements) {
    int avg=mean(array, numElements);
    if (!avg) {return NAN;}
    int sum;
    for (int i = 0; i < numElements; i++) {
        int nr=avg-array[i];
        sum+=nr*nr;
    }
    return sqrt(sum/numElements);
}


std::pair<double, double> max2(double array[], int numElements) {
    if (numElements == 0) {
        return std::make_pair(NAN, NAN);
    }
    if (numElements == 1) {
        return std::make_pair(array[0], array[0]);
    }

    double max1 = array[0];
    double max2 = array[1];

    if (max2 > max1) std::swap(max1, max2);

    for (int i = 2; i < numElements; ++i) {
        if (array[i] > max1) {
            max2 = max1;
            max1 = array[i];
        } else if (array[i] > max2) {
            max2 = array[i];
        }
    }

    return std::make_pair(max1, max2);
}
int countWords(std::string text) {
    int nr=0;
    std::stringstream ss(text);
    std::string words;
    while (ss >> words) {
        nr++;
    }
    return nr;
}
int sumwords(std::string text) {
    int nr=0;
    int sum=0;
    std::stringstream ss(text);
    std::string words;
    while (ss >> words) {
        std::stringstream convert(words);
        if (convert >> nr) {
            sum += nr;
        }
    }
    return sum;
}
string code(string text) {

    for (int i = 0; i < text.length(); i++) {
        //cout<<text[i];
        text[i]++;
    }
    return text;
}
string capitalize(string text) {
    std::stringstream ss(text);
    std::string words;
    string result;
    while (ss >> words) {
        words[0]=toupper(words[0]);
        for (int i = 1; i < words.length(); i++) {
            words[i]=tolower(words[i]);
        }
        result += words;
        result+=" ";
    }
    return result;
}