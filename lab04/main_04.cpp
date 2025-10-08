#include <iostream>
#include "polynom.h"
using namespace std;
int main() {
    double d1[]={1, 2, 3, 4, 5};
    double d2[]={10, 12, 53, 44, 95};
    Polynomial *p1 = new Polynomial(4, d1);
    Polynomial *p2 = new Polynomial(4, d2);
    cout<<*p1<<endl;
    cout<<p1->degree()<<endl;
    cout<<*p2<<endl;
    cout<<p2->degree()<<endl;
    cout<<*p1+*p2<<endl;
    cout<<(*p1+*p2).evaluate(5)<<endl;
    cout<<*p1-*p2<<endl;
    cout<<(*p1-*p2).evaluate(9)<<endl;
    cout<<-*p1<<endl;
    cout<<(-*p1).evaluate(19)<<endl;
    cout<<p1->derivative()<<endl;
    cout<<p2->derivative()<<endl;

    return 0;
}