//
// Created by denes on 2025. 12. 09..
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "KonyvtariStatisztika.h"


void KonyvtariStatisztika::konyvekBetoltese(string filename) {
    ifstream f(filename);
    if(!f.is_open()){
        cerr<<"Hiba!";
        exit (404);
    }
    string temp;
    getline(f, temp);
    while(getline(f,temp)){
        stringstream ss(temp);
        string isbn;
        getline(ss, isbn, ';');
        string cim;
        getline(ss, cim, ';');
        string iro;
        getline(ss, iro, ';');
        string y;
        getline(ss, y);
        int year=stoi(y);
        Konyv temp(isbn, cim, iro, year);
        konyvek.insert(make_pair(isbn, temp));
    }
}

void KonyvtariStatisztika::printKonyvek() {
    for(pair<string, Konyv>t : konyvek){
        cout<<t.second<<endl;
    }
}

void KonyvtariStatisztika::kolcsonzesekBetoltese(string filename) {
    ifstream f(filename);
    if(!f.is_open()){
        cerr<<"Hiba!";
        exit (404);
    }
    string temp;
    getline(f, temp);
    while(getline(f,temp)){
        stringstream ss(temp);
        string nev;
        getline(ss, nev, ';');
        string isbn;
        getline(ss, isbn, ';');
        string date;
        getline(ss, date);
        if(!kolcsonzesek.contains(nev)){
            vector<string>isbns;
            isbns.push_back(isbn);
            kolcsonzesek.insert(make_pair(nev, isbns));
        }
        else{
            kolcsonzesek.at(nev).push_back(isbn);
        }
        if(!isbngyakorisag.contains(isbn)){
            isbngyakorisag.insert(make_pair(isbn, 1));
        }
        else{
            isbngyakorisag.at(isbn)++;
        }
    }
}

void KonyvtariStatisztika::printKolcsonzesek() {
    for(pair<string, vector<string>>t:kolcsonzesek){
        cout<<t.first<<": ";
        for(string s:t.second){
            cout<<s<<", ";
        }
        cout<<endl;
    }
}

void KonyvtariStatisztika::printisbngyakorisag() {
    for(pair<string, int>t:isbngyakorisag){
        cout<<t.first<<": "<<t.second<<endl;
    }
}

void KonyvtariStatisztika::legnepszerubbKonyv() {
    int max=0;
    string isbn;
    for(pair<string, int>t:isbngyakorisag){
        if(t.second>max){
            max=t.second;
            isbn=t.first;
        }
    }
    cout<<konyvek.at(isbn).getCim()<<" ("<<max<<" kolcsonzes).";

}

void KonyvtariStatisztika::olvasoKolcsonzesei(string nev) {
    vector<string> isbns=kolcsonzesek.at(nev);
    if(!isbns.empty()){
        for(string t:isbns){
            cout<<konyvek.at(t)<<endl;
        }
    }
    else{
        cout<<"Nincsenek kolcsonzott konyvek."<<endl;
    }

}

void KonyvtariStatisztika::szerzoStatisztika() {
    map<string, int>szerzok;
    for(pair<string, Konyv>t : konyvek){
        if(!szerzok.contains(t.second.getSzerzo())){
            szerzok.insert(make_pair(t.second.getSzerzo(), 1));
        }
        else{
            szerzok.at(t.second.getSzerzo())++;
        }
    }
    for(pair<string, int>t:szerzok){
        cout<<t.first<<": "<<t.second<<endl;
    }
}

void KonyvtariStatisztika::reszletesStatisztika() {
    cout<<"Konyvek szama: "<<konyvek.size()<<endl;
    int sum=0;
    for(pair<string, int> t : isbngyakorisag){sum+=t.second;}
    cout<<"Kolcsonzesek szama: "<<sum<<endl;
    cout<<"Aktiv olvasok: "<<kolcsonzesek.size()<<endl;
    cout<<"Kolcsonzesi lista olvasok szerint:"<<endl;
    for(pair<string, vector<string>> t: kolcsonzesek){
        cout<<t.first<<": "<<endl;
        for(string s:t.second){
            cout<<"     "<<konyvek.at(s)<<endl;
        }
        cout<<endl;
    }

}
