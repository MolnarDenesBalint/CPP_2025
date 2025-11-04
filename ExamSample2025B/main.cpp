#include <iostream>
#include "Library.h"

int main() {
   Library l;
   if(!l.loadFromFile("bemenet.txt")){
       cout<<"Beolvasasi hiba.";
   }
   l.displayAll();
   l.sotrByTitle();
   cout<<endl<<"Rendezve cim szerint:"<<endl;
   l.displayAll();
   l.sortByPages();
   cout<<endl<<"Rendezve oldal szerint:"<<endl;
   l.displayAll();
   l.sortBYAuthorAndYear();
   cout<<endl<<"Rendezve iro es ev szerint:"<<endl;
   l.displayAll();
   vector<Book> b=l.searchByTitle("Ura");
   cout<<endl<<"A kereses eredmenye:"<<endl;
   for (Book bk:b){
       cout<<bk;
   }
    return 0;
}
