//
// Created by denes on 2025. 10. 22..
//

#include "QuizItem.h"
int QuizItem::count=0;

QuizItem::QuizItem(const string question, const vector<string> answers, const int correctAnswer) {
    this->id=count;
    count++;
    this->question=question;
    this->answers=answers;
    this->correctAnswer=correctAnswer;
}

int QuizItem::getId() const {
    return id;
}

const string &QuizItem::getQuestion() const {
    return question;
}

void QuizItem::setQuestion(const string &question) {
    QuizItem::question = question;
}

const vector<string> &QuizItem::getAnswers() const {
    return answers;
}

void QuizItem::setAnswers(const vector<string> &answers) {
    QuizItem::answers = answers;
}

int QuizItem::getCorrectAnswer() const {
    return correctAnswer;
}

void QuizItem::setCorrectAnswer(int correctAnswer) {
    QuizItem::correctAnswer = correctAnswer;
}


