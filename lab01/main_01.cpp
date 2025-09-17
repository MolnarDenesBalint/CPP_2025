#include <iostream>

#include "functions.h"
using namespace std;
int main() {
    for (int i = 0; i <= 127; ++i) {
        cout<<i<<": "<<countbits(i)<<endl;

    }

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)) {
            cout<<i<<" ---> " << n <<endl;
        } else {
            cout<<"Impossible operation!" << endl;
        }
    }
    double a[]={0.0, 1.2, 6.3, 4.63, 99.6, 99.5};
    cout<<"Atlag: "<<mean(a, sizeof(a)/sizeof(a[0]))<<endl;
    cout<<"Szoras: "<<stddev(a, sizeof(a)/sizeof(a[0]))<<endl;
    cout<<"Pair: "<<max2(a, sizeof(a)/sizeof(a[0])).first <<" "<<max2(a, sizeof(a)/sizeof(a[0])).second<<endl;
    string mondat="Programing is fun.";
    string mondat2="Programing is 1 2 99 0 fun. 15 6";
    string mondat3="abcdefghijklmnopqrst";
    cout<<"Szavak: "<<countWords(mondat)<<endl;
    cout<<"Szavak osszege: "<<sumwords(mondat2)<<endl;
    cout<<"Kodolt: "<<code(mondat3)<<endl;
    cout<<"Nagybetus: "<<capitalize(mondat)<<endl;
    return 0;
}
