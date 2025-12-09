#include <iostream>
#include "Konyv.h"
#include "KonyvtariStatisztika.h"

int main() {
   //Konyv k("978-0-123456-78-9", "C++ Programozas", "Bjarne Stroustrup", 2013);
   //cout<<k;
   KonyvtariStatisztika ks;
   ks.konyvekBetoltese("konyvek.txt");
   ks.printKonyvek();
   ks.kolcsonzesekBetoltese("kolcsonzesek.txt");
   ks.printKolcsonzesek();
   ks.printisbngyakorisag();
   cout<<"Legnepszerubb konyv: ";
   ks.legnepszerubbKonyv();
   cout<<endl<<"---Kis Anna kolcsonzott konyvei:---"<<endl;
   ks.olvasoKolcsonzesei("Kiss Anna");
   cout<<endl<<"---Szerzo statisztika---"<<endl;
   ks.szerzoStatisztika();
   cout<<endl<<"---Reszletes statisztika---"<<endl;
   ks.reszletesStatisztika();
    return 0;
}
