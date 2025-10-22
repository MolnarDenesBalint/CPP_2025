//
// Created by denes on 2025. 10. 22..
//

#ifndef LAB6_QUIZGAME_H
#define LAB6_QUIZGAME_H

#include "user.h"
#include "Quiz.h"

class QuizGame{
    User* u;
    vector<Quiz>qs;
public:
    QuizGame(User *u, vector<Quiz>q);
    void run(User *u, Quiz* q);
    void runquizes();

};
#endif //LAB6_QUIZGAME_H
