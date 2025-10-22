//
// Created by denes on 2025. 10. 22..
//

#ifndef LAB6_QUIZITEM_H
#define LAB6_QUIZITEM_H
#include <string>
#include <vector>

using namespace std;
class QuizItem{
    static int count;
    int id;
    string question;
    vector<string> answers;
    int correctAnswer;
public:
    QuizItem(const string question, const vector<string> answers, const int correctAnswer);

    int getId() const;

    const string &getQuestion() const;

    void setQuestion(const string &question);

    const vector<string> &getAnswers() const;

    void setAnswers(const vector<string> &answers);

    int getCorrectAnswer() const;

    void setCorrectAnswer(int correctAnswer);


};
#endif //LAB6_QUIZITEM_H
