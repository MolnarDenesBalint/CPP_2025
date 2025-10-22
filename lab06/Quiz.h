//
// Created by denes on 2025. 10. 22..
//

#ifndef LAB6_QUIZ_H
#define LAB6_QUIZ_H
#include<string>
#include "QuizItem.h"

using namespace std;

class Quiz{
    static int count;
    int quizId;
    string quizName;
    vector<QuizItem>items;
    bool isReady;

public:
    Quiz(const vector<QuizItem> &items, const string &quizName);
    void addQuizItem(QuizItem i);
    void finalize();
    const vector<QuizItem> &getItems() const;

    int getQuizId() const;
};
#endif //LAB6_QUIZ_H
