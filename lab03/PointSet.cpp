//
// Created by denes on 2025. 10. 01..
//

#include <random>
#include <algorithm>
#include <iostream>
#include "PointSet.h"

void PointSet::computeDistances() {
    for(int i=0; i<points.size(); i++){
        for (int j = i; j < points.size(); ++j) {
            distances.push_back(points.at(i).distanceTo(points.at(j)));

        }
    }
}

PointSet::PointSet(int n) {
    this->n=n;
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M);
    while(points.size()<n){
        int x=dist(mt), y=dist(mt);
        bool ok=false;
        for (int j = 0; j < points.size(); ++j) {
            if(points.at(j).getX()==x && points.at(j).getY()==y){
                ok=true;
            }
        }
        if(ok==false){
            points.push_back(Point(x, y));
        }
    }
    computeDistances();
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(),distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(),distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for(Point p:points){
        cout<<p.getX()<<" - "<<p.getY()<<endl;
    }
}

void PointSet::printDistances() const {
    for(double d:distances){
        cout<<d<<endl;
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), []
    (const Point& a, const Point& b)
    {return b.getX()<a.getX();});
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), []
            (const Point& a, const Point& b)
    {return b.getY()<a.getY();});
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    return unique(distances.begin(), distances.end())-distances.begin();
}






