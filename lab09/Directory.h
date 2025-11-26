//
// Created by denes on 2025. 11. 12..
//

#ifndef LAB9_DIRECTORY_H
#define LAB9_DIRECTORY_H

#include <vector>
#include "FileSystemItem.h"

class Directory : public FileSystemItem{
    vector<FileSystemItem*> children;
public:
    Directory(const string& name);
    Directory(const Directory& other);
    Directory & operator =(const Directory& other);
    ~Directory();
    void add(FileSystemItem* item);
    void remove(const string& name);
    FileSystemItem* find(const string& name);
    long getSize() const override;
    string getName() const override;
    void display(int depth) const override;
    Directory& operator +=(FileSystemItem & what);
    Directory& operator-=(FileSystemItem & what);
    FileSystemItem* clone() const override;
    friend ostream& operator <<(ostream &os, FileSystemItem &what);


};
#endif //LAB9_DIRECTORY_H
