//
// Created by denes on 2025. 11. 12..
//

#ifndef LAB9_FILE_H
#define LAB9_FILE_H

#include "FileSystemItem.h"

class File : public FileSystemItem{
public:
    File(const string& name, long size);
    File(const File& other);
    long getSize() const override;
    string getName() const override;
    void display(int depth ) const override;
    FileSystemItem* clone() const override;
};
#endif //LAB9_FILE_H
