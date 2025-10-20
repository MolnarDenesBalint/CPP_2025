//
// Created by denes on 2025. 10. 20..
//

#include "video.h"

Video::Video(const string &id, const string &title, double length, const string &uploader, long uploaded) {
    this->id=id;
    this->title=title;
    this->length=length;
    this->uploader=uploader;
    this->uploaded=uploaded;
}

const string &Video::getId() const {
    return this->id;
}

double Video::getLength() const {
    return this->length;
}

const string &Video::getTitle() const {
    return this->title;
}

const string &Video::getUploader() const {
    return this->uploader;
}

long Video::getUploaded() const {
    return this->uploaded;
}

ostream &operator<<(ostream &os, const Video &video) {
    os<<video.title<<" - "<<video.length << " -> "<< video.uploader<<" - "<<video.uploaded/10000<<"."<<(video.uploaded/100)%100<<"."<<video.uploaded%100;
    return os;
}


