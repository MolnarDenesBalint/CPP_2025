//
// Created by denes on 2025. 10. 20..
//

#include <iostream>
#include "PlayList.h"
using namespace std;
PlayList::PlayList(int capacity) {
    this->capacity=capacity;
    this->count=0;
    list = new Video*[capacity];
}

PlayList::PlayList(const PlayList &copy) {
    this->title = copy.title;
    this->capacity = copy.capacity;
    this->count = copy.count;

    this->list = new Video*[capacity];
    for (int i = 0; i < count; ++i) {
        this->list[i] = copy.list[i];
    }
}

PlayList::PlayList(PlayList &&move) noexcept {
    this->title=move.title;
    move.title.clear();
    this->capacity=move.capacity;
    move.capacity=0;
    this->count=move.count;
    move.count=0;
    this->list=move.list;
    move.list=nullptr;
}

PlayList::~PlayList() {
    this->list=nullptr;
    this->title.clear();
    this->capacity=0;
    this->count=0;
}

const string &PlayList::getTitle() const {
    return this->title;
}

void PlayList::setTitle(const string &title) {
    this->title=title;
}

int PlayList::videos() const {
    return this->count;
}

void PlayList::append(Video *video) {
    if(count == capacity) {
        int newCap = (capacity == 0) ? 1 : capacity * 2;  // legalább 1 vagy duplázás
        Video **newList = new Video*[newCap];
        for (int i = 0; i < count; ++i) {
            newList[i] = list[i];
        }
        delete[] list;
        list = newList;
        capacity = newCap;
    }
    list[count] = video;
    ++count;
}


Video *PlayList::operator[](int index) {
    return this->list[index];
}

const Video *PlayList::operator[](int index) const {
    return this->list[index];
}

PlayList &PlayList::operator=(PlayList &&move) noexcept {
    this->title=move.title;
    move.title.clear();
    this->capacity=move.capacity;
    move.capacity=0;
    this->count=move.count;
    move.count=0;
    this->list=move.list;
    move.list=nullptr;
    return *this;
}

PlayList &PlayList::operator=(const PlayList &copy) {
    if (this != &copy) {
        delete[] this->list;
        this->title = copy.title;
        this->capacity = copy.capacity;
        this->count = copy.count;

        this->list = new Video*[capacity];
        for (int i = 0; i < count; ++i) {
            this->list[i] = copy.list[i];
        }
    }
    return *this;
}

ostream &operator<<(ostream &os, const PlayList &list) {
   os<<list.title<<" - "<<list.count<<": "<<endl;
   for(int i=0;i<list.count; i++){
       os<<*list.list[i]<<endl;
   }
    return os;
}

PlayList operator+(const PlayList &a, const PlayList &b) {
    string name=a.title + " and "+ b.title;
    int capacity=a.capacity+b.capacity;
    PlayList p(capacity);
    p.setTitle(name);
    for(int i=0; i<a.count; i++){
        p.append(a.list[i]);
    }
    for(int i=0; i<b.count; i++){
        p.append(b.list[i]);
    }
    return p;
}
