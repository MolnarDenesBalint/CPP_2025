#include <iostream>
#include "SimpleTextGenerator.h"

int main() {
    SimpleTextGenerator stg;
    stg.trainFromFile("bemenet.txt");
    string result = stg.generate("time for", 10);
    cout<<"A generalt mondat: "<<result<<endl;
    return 0;
}