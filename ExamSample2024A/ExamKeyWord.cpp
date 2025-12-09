//
// Created by denes on 2025. 12. 08..
//

#include <fstream>
#include <sstream>
#include <algorithm>
#include "ExamKeyWord.h"
#include "iostream"

ExamKeyWord::ExamKeyWord(const char * filename) {
    ifstream f (filename) ;
    if(!f.is_open()){cerr<<"Hiba";return;}
    string temp;
    while(getline(f, temp)){
        stringstream ss(temp);
        string name;
        vector<string>kw;
        ss>>name;
        string temp;
        for(char& c:name){
            if(c !=':' && c!='_'){
                temp+=c;
            }
            if(c=='_'){
                temp+=' ';
            }
        }
        name=temp;
        string words;
        getline(ss, words);
        string cleanwords;
        for(char&c :words){
            if(c==' '  || isalpha(c) || c==','){
                cleanwords+=c;
            }
        }
        stringstream ss2(cleanwords);
        while(getline(ss2, temp, ',')){
            string cleanword;
            if(temp[0]==' '){
                temp=temp.substr(1);
            }


           kw.push_back(temp);

        }
        keywords.insert(make_pair(name, kw));
    }
    for(pair<string, vector<string>> t: keywords){
        cout<<t.first<<":";
        for(string s:t.second){cout<<s<<",";}
        cout<<endl;
    }
    f.close();
}
