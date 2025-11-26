//
// Created by denes on 2025. 11. 12..
//

#include "File.h"

File::File(const string &name, long size): FileSystemItem() {
    this->size=size;
    this->name=name;
}
File::File(const File &other) : FileSystemItem(){
    this->name=other.name;
    this->size=other.size;
}

long File::getSize() const {
    return this->size;
}

void File::display(int depth) const {
    cout<<this->name<<" ("<<this->size<<")"<<endl;
}

FileSystemItem *File::clone() const{
    File * copy=new File(*this);
    return copy;
}

string File::getName() const {
    return this->name;
}



