//
// Created by denes on 2025. 11. 12..
//
#include <string>
#include <iostream>
using namespace std;
#ifndef LAB9_FILESYSTEMITEM_H
#define LAB9_FILESYSTEMITEM_H
class FileSystemItem{
protected :
    string name;
    long size;
public:
    virtual long getSize() const = 0;
    virtual string getName() const = 0;
    virtual void display(int depth = 0) const = 0;
    virtual FileSystemItem* clone() const = 0;
    friend ostream& operator <<(ostream &os, FileSystemItem &what);
    friend bool operator <(FileSystemItem i1, FileSystemItem i2);
};
#endif //LAB9_FILESYSTEMITEM_H
