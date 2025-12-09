//
// Created by denes on 2025. 12. 08..
//

#ifndef EXAMSAMPLE2024A_EXAMKEYWORD_H
#define EXAMSAMPLE2024A_EXAMKEYWORD_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class ExamKeyWord{
    map <string, vector<string>> keywords;
public:
    ExamKeyWord(const char* filename);
};
#endif //EXAMSAMPLE2024A_EXAMKEYWORD_H
