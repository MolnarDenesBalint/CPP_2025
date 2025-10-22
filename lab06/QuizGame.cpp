//
// Created by denes on 2025. 10. 22..
//

#include <iostream>
#include "QuizGame.h"


void QuizGame::run(User*u, Quiz*q) {
    int ca=0, ta=0;
    vector<QuizItem>qi=q->getItems();

    for(QuizItem i:qi){
        cout<<i.getQuestion()<<endl;
        int nr=1;
        for(string a:i.getAnswers()){
            cout<<nr<<". "<<a<<endl;
            nr++;
        }
        cout<<"Add meg a valasz sorszamat:";
        int answ;
        cin>>answ;
        if(answ==i.getCorrectAnswer()){
           ca++;
           cout<<"Helyes valasz!"<<endl;
        }
        ta++;
    }
    cout<<"Helyes valaszok szama: "<<ca<<endl;
    double p=ca/ta;
    cout<<"Pontszam: "<<p<<endl;
    this->u->addResult(q->getQuizId(),p);
}

QuizGame::QuizGame(User *u, vector<Quiz> q) {
    this->u=u;
    this->qs=q;
}

void QuizGame::runquizes() {
    for(auto i:qs){
        run(u,&i);
    }
}
