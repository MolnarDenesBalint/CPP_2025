#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_map>

using namespace std;
int main() {
    cout<<"EX.1."<<endl;
    vector<string> fruits {"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};
    auto it =find_if(fruits.begin(), fruits.end(), [](const string &s){
        return s.find("berry")!=string::npos;
    });
    if(it!=fruits.end())
    {
        cout<<"van"<<endl;
    }
    else{
        cout<<"nincs"<<endl;
    }

    cout<<"EX.2."<<endl;
    vector<int>numbers{12,2,32,4,52,6,72,8,92,10,112,12,1052,9856,15498452,1215451564,215919512};
    bool paros= all_of(numbers.begin(), numbers.end(), [](const int& nr)
    {return nr%2==0;});
    if(paros){cout<<"Az osszes paros."<<endl;}
    else{cout<<"Van paratlan is"<<endl;}

    cout<<"EX.3."<<endl;
    numbers.clear();
    numbers={1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator it2 =numbers.begin();
    for_each(numbers.begin(), numbers.end(),  [&it2](const int& a){
        *(it2++)=a*2;
    });
    cout<<"Numbers: ";
    for(int i:numbers){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"EX.4."<<endl;
    vector<string> months {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    int nr=0;
    for_each(months.begin(), months.end(), [&nr](const string &s){
        if(s.size()==5){nr++;}
    });
    cout<<"5 betus honapok szama: "<<nr<<endl;

    cout<<"EX.6."<<endl;
    numbers.clear();
    numbers={1,9,4,6,8,2,5,7, 19, 15, 14, 11, 16};
    cout<<"A tomb alaphelyzetben: ";
    for(int i:numbers){
        cout<<i<<" ";
    }
    cout<<endl;
    sort(numbers.begin(), numbers.end(), [](const int &a, const int &b){
        return a<b;
    });
    cout<<"A tomb sort utan: ";
    for(int i:numbers){
        cout<<i<<" ";
    }
    cout<<endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    shuffle(numbers.begin(), numbers.end(), gen);
    cout<<"A tomb ujra osszekavarva: ";
    for(int i:numbers){
        cout<<i<<" ";
    }
    cout<<endl;
    sort(numbers.begin(), numbers.end(),greater<int>());
    cout<<"A tomb 2. sort utan: ";
    for(int i:numbers){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"EX.6."<<endl;
    std::vector<std::pair<std::string, double>> temps = {
            {"Januar", -0.5},
            {"Februar", 1.2},
            {"Marcius", 6.0},
            {"Aprilis", 11.5},
            {"Majus", 16.8},
            {"Junius", 20.2},
            {"Julius", 22.3},
            {"Augusztus", 21.9},
            {"Szeptember", 17.1},
            {"Oktober", 11.3},
            {"November", 5.5},
            {"December", 0.8}
    };
    cout<<"A homersekletek: "<<endl;
    for(const pair<std::string, double> &p:temps){
        cout<<p.first<<" - "<<p.second<<endl;
    }
    cout<<endl;
    sort(temps.begin(), temps.end(), [](const pair<string, double>& p, const pair<string, double>& p2){
        return p.second<p2.second;
    });
    cout<<"A homersekletek rendezve: "<<endl;
    for(const pair<std::string, double> &p:temps){
        cout<<p.first<<" - "<<p.second<<endl;
    }
    cout<<endl;

    cout<<"EX.7."<<endl;
    vector<double> numbers2={-1.2, 6.4, -11.8, 5.3, -2.0, -11.9, 5.9};
    cout<<"A tomb : ";
    for(double i:numbers2){
        cout<<i<<" ";
    }
    cout<<endl;
    sort(numbers2.begin(), numbers2.end(), [](const double &a, const double &b){
        return abs(a)<abs(b);
    });
    cout<<"A tomb abs szerint rendezve: ";
    for(double i:numbers2){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"EX.8."<<endl;
    cout<<"A honapos tomb: ";
    for(const string &s:months){
        cout<<s<<" ";
    }
    cout<<endl;
    for_each(months.begin(), months.end(), [](string &s){
        transform(s.begin(), s.end(),s.begin(), [](char c){
            return tolower(c);
        });
    });
    cout<<"A honapos tomb kisbetukkel: ";
    for(const string &s:months){
        cout<<s<<" ";
    }
    cout<<endl;

    cout<<"EX.8."<<endl;
    vector<char> abc = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    cout<<"Angol abc: ";
    for(const char &c: abc){
        cout<<c<<" ";
    }
    cout<<endl;
    shuffle(abc.begin(), abc.end(), gen);
    cout<<"Angol abc osszekeverve: ";
    for(const char &c: abc){
        cout<<c<<" ";
    }
    cout<<endl;
    std::unordered_map<char, int> char_ranks;
    for (int i = 0; i < abc.size(); ++i) {
        char_ranks[abc[i]] = i;
    }
    sort(months.begin(), months.end(), [&char_ranks](const string &a, const string&b){
        char c=a[0];
        int cp=char_ranks.at(c);
        char c1=b[0];
        int c1p=char_ranks.at(c1);
        return c1<c;
    });
    cout<<"A honapok rendezve: "<<endl;
    for(const string &s:months){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}