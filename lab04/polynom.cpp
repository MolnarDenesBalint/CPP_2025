//
// Created by denes on 2025. 10. 08..
//

#include <algorithm>
#include <valarray>
#include "polynom.h"
using namespace std;
Polynomial::Polynomial(int degree, const double *coefficients) {
    capacity=degree+1;
    this->coefficients=new double[capacity];
    copy(coefficients, coefficients+degree+1, this->coefficients);
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity=that.capacity;
    this->coefficients=new double[that.capacity];
    copy(that.coefficients, that.coefficients+that.capacity, this->coefficients);
    /*for(int i=0; i<that.capacity; i++){
        this->coefficients[i]=that.coefficients[i];
    }*/
}

Polynomial::~Polynomial() {
    this->capacity=0;
    delete[] this->coefficients;
    this->coefficients=nullptr;
}

double Polynomial::evaluate(double x) const {
    double result=0;
    for(int i=0; i<capacity; i++){
        result += coefficients[i]*pow(x, capacity-1-i);
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    double *newcoefficients= new double[capacity-1];
    for(int i=0; i<capacity-1; i++){
        newcoefficients[i]=coefficients[i]*capacity-1;
    }
    Polynomial newp(capacity-2, newcoefficients);
    delete [] newcoefficients;
    return newp;
}

double Polynomial::operator[](int index) const {
    return coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    double *newcoefficients= new double[a.capacity];
    for(int i=0; i<a.capacity; i++){
        newcoefficients[i]=-a.coefficients[i];
    }
    Polynomial newp(a.capacity-1, newcoefficients);
    delete [] newcoefficients;
    return newp;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    if(a.capacity>b.capacity){
        double *newcoefficients=new double[a.capacity];
        copy(a.coefficients, a.coefficients+a.capacity, newcoefficients);
        for(int i=b.capacity-1; i>=0; i--){
            newcoefficients[i]+=b.coefficients[i];
        }
        Polynomial newp(a.capacity-1, newcoefficients);
        delete [] newcoefficients;
        return newp;
    }
    else{
        double *newcoefficients=new double[b.capacity];
        copy(b.coefficients, b.coefficients+a.capacity, newcoefficients);
        for(int i=a.capacity-1; i>=0; i--){
            newcoefficients[i]+=a.coefficients[i];
        }
        Polynomial newp(b.capacity-1, newcoefficients);
        delete [] newcoefficients;
        return newp;
    }
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    if(a.capacity>b.capacity){
        double *newcoefficients=new double[a.capacity];
        copy(a.coefficients, a.coefficients+a.capacity, newcoefficients);
        for(int i=b.capacity-1; i>=0; i--){
            newcoefficients[i]-=b.coefficients[i];
        }
        Polynomial newp(a.capacity-1, newcoefficients);
        delete [] newcoefficients;
        return newp;
    }
    else{
        double *newcoefficients=new double[b.capacity];
        copy(b.coefficients, b.coefficients+a.capacity, newcoefficients);
        for(int i=a.capacity-1; i>=0; i--){
            newcoefficients[i]-=a.coefficients[i];
        }
        Polynomial newp(b.capacity-1, newcoefficients);
        delete [] newcoefficients;
        return newp;
    }
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    out<<"P(x)=";
    for(int i=0; i<what.capacity-1; i++){
        out<<what.coefficients[i]<<"X^"<<what.capacity-i-1<<"+";
    }
    out<<what.coefficients[what.capacity-1];
    return out;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    return Polynomial(0, nullptr);
}

