//
// Created by denes on 2025. 12. 03..
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <random>
#include "SimpleTextGenerator.h"

void SimpleTextGenerator::trainFromText(string trainingText) {
    vector<string>words;
    stringstream ss (trainingText);
    string temp;
    while(ss>>temp){
        words.push_back(temp);
    }
    for(string& s :words){
        string temp;
        for_each(s.begin(), s.end(), [&temp](char& c){ c= tolower(c);
        if(isalpha(c)) {
            temp += c;
        }});
        s=temp;
    }
    for(int i=0; i<words.size()-1; i++){
        vector<string> w;
        w.push_back(words[i+2]);
        if(data.find(words[i]+" "+words[i+1])==data.end()){
            data.insert(make_pair(words[i]+" "+words[i+1], w) );
        }
        else{
            string search=words[i+2];
            auto it = find_if(data.at(words[i]+" "+words[i+1]).begin(), data.at(words[i]+" "+words[i+1]).end(), [search](string& temp){return temp ==search;});
            if(it==data.at(words[i]+" "+words[i+1]).end()){
                data.at(words[i]+" "+words[i+1]).push_back(words[i+2]);
            }
        }
    }
    for(pair<string, vector<string>> t: data){
        cout<<t.first<<" :";
        for(string t2: t.second){
            cout<<t2<<" ";
        }
        cout<<endl;
    }
}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream f (filename) ;
    if(!f.is_open()){cerr<<"Hiba";return;}
    string temp;
    while(getline(f, temp)){
        trainFromText(temp);
    }
    f.close();
}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    vector<string>result;
    stringstream ss(startWords);
    vector<string>sw;
    string temp;
    while(ss>>temp){sw.push_back(temp);}
    for(string s:sw){
        result.push_back(s);
    };
    random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int>dist(0, 1000);
    int random=dist(gen);
    result.push_back(data.at(result[0]+" "+result[1]).at(random%data.at(result[0]+" "+result[1]).size()));
    while(result.size()<numWords){
        int size=result.size();
        if(data.at(result[size-2]+" "+result[size-1]).size()==0){
            break;
        }
        result.push_back(data.at(result[size-2]+" "+result[size-1]).at(random%data.at(result[size-2]+" "+result[size-1]).size()));
    }
    string r;
    for(string temp:result){
        r+=temp;
        r+=" ";
    }
    return r;
}
