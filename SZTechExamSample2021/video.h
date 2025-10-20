//
// Created by denes on 2025. 10. 20..
//

#ifndef SZTECHEXAMSAMPLE2021_VIDEO_H
#define SZTECHEXAMSAMPLE2021_VIDEO_H
#include <string>
#include <ostream>
using namespace std;

class Video {
    string id;
    string title;
    double length;
    string uploader;
    long uploaded;
public:
    Video(const string &id, const string &title, double length, const string &uploader, long uploaded);
    const string &getId() const;
    const string &getTitle() const;
    double getLength() const;
    const string &getUploader() const;
    long getUploaded() const;
    friend ostream &operator<<(ostream &os, const Video &video);
};

#endif //SZTECHEXAMSAMPLE2021_VIDEO_H
