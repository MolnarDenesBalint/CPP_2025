//
// Created by denes on 2025. 10. 20..
//

#ifndef SZTECHEXAMSAMPLE2021_PLAYLIST_H
#define SZTECHEXAMSAMPLE2021_PLAYLIST_H
#include "Video.h"
using namespace std;

class PlayList {
    string title;
    Video **list;
    int capacity;
    int count;
public:
    PlayList(int capacity = 200);
    PlayList(const PlayList &copy);
    PlayList(PlayList &&move) noexcept;
    ~PlayList();

    const string &getTitle() const;
    void setTitle(const string &title);
    int videos() const;
    void append(Video *video);
    void sort(bool less(const Video &a, const Video &b));
    Video *operator[](int index);
    const Video *operator[](int index) const;
    PlayList &operator=(const PlayList &copy);
    PlayList &operator=(PlayList &&move) noexcept;

    friend PlayList operator+(const PlayList &a, const PlayList &b);
    friend ostream &operator<<(ostream &os, const PlayList &list);
};

#endif //SZTECHEXAMSAMPLE2021_PLAYLIST_H
