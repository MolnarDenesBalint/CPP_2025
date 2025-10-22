//
// Created by denes on 2025. 10. 22..
//

#include <stdexcept>
#include "Quiz.h"
int Quiz::count=0;
Quiz::Quiz(const vector<QuizItem> &items, const string &quizName){
    this->quizId=Quiz::count;
    Quiz::count++;
    this->items=items;
    this->quizName=quizName;
    this->isReady=false;
}

void Quiz::addQuizItem(QuizItem i) {
    if(this->isReady==false){
        this->items.push_back(i);
    }
    else{
        throw invalid_argument("A quiz mar le van zarva!");
    }
}

void Quiz::finalize() {
    this->isReady=true;
}

const vector<QuizItem> &Quiz::getItems() const {
    return items;
}

int Quiz::getQuizId() const {
    return quizId;
}


