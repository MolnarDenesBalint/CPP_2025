#include <iostream>
#include <fstream>
#include "Quiz.h"
#include "QuizGame.h"

using namespace std;
int main() {
    User u("Bela");
    vector<Quiz>qs;
    vector<string> files={"quiz.txt", "quiz2.txt"};
for(int i=0; i<files.size(); i++){
    ifstream f(files.at(i));
    if(!f.is_open()){return 404;}
    vector<QuizItem>items;
    string q;
    vector<string>answers;
    int corrindex;
    while(!f.eof()){
        string temp;
        getline(f, temp);
        if(temp[0]=='Q'){
            q=temp.substr(2);
        }
        else if(temp[0]=='A')
            answers.push_back(temp.substr(2));
        else{
            corrindex= stoi(temp);
            QuizItem *qi=new QuizItem(q, answers, corrindex);
            items.push_back(*qi);
            answers.clear();
        }
    }
    Quiz *q1=new Quiz(items, "Quiz1");
    qs.push_back(*q1);

}


    QuizGame game(&u, qs);
    game.runquizes();
    return 0;
}