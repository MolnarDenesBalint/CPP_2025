//
// Created by denes on 2025. 12. 03..
//

#ifndef LAB12_SIMPLETEXTGENERATOR_H
#define LAB12_SIMPLETEXTGENERATOR_H

#include <vector>
#include <map>
#include "TextGenerator.h"

class SimpleTextGenerator: public TextGenerator {
    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    void printData() const;
};
#endif //LAB12_SIMPLETEXTGENERATOR_H
