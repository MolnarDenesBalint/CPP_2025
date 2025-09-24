//
// Created by denes on 2025. 09. 24..
//

#include "utils.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <math.h>
#include <random>
using namespace std;
double distance(const Point& a, const Point& b) {
    return sqrt(pow((b.getX() - a.getX()), 2) + pow((b.getY() - a.getY()),2) );
}
bool isSquare(const Point& a, const Point& b, const Point& c, const Point&d) {
    double d1 = distance(a, b);
    double d2 = distance(a, c);
    double d3 = distance(a, d);
    double d4 = distance(b, c);
    double d5 = distance(b, d);
    double d6 = distance(c, d);
    if (d1 > 0 && d1 == d2 && d2 == d4 && d4 == d5) {
        if (d3 == d6) {
            return true;
        }
    }
    if (d2 > 0 && d2 == d1 && d1 == d6 && d6 == d5) {
        if (d3 == d4) {
            return true;
        }
    }
    if (d3 > 0 && d3 == d1 && d1 == d6 && d6 == d4) {
        if (d2 == d5) {
            return true;
        }
    }
    return false;
}

void testIsSquare(const char * filename) {
    std::ifstream f(filename);
    if (!f.is_open()) {exit(404);}
    for (int i=0; i<10; i++) {
        int x1, x2,x3, x4, y1, y2, y3, y4;
        f>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        Point p1(x1, y1 );
        Point p2(x2, y2 );
        Point p3(x3, y3 );
        Point p4(x4, y4 );
        p1.print();
        p2.print();
        p3.print();
        p4.print();
        if (isSquare(p1,p2,p3,p4)==true){ std::cout<<"KOCKA!!!!"<<endl;}
        else{cout<<"NEM KOCKA!!!"<<endl;}
    }

}
Point* createArray(int numPoints) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2000);
    int x, y;
    Point* Array=new Point[numPoints];
    for (int i=0; i<numPoints; i++) {
        x = distrib(gen);
        y = distrib(gen);
        Array[i]=Point(x, y);
    }
    return Array;
}
void printArray(Point* points, int numPoints) {
    for (int i=0; i<numPoints; i++) {
        points[i].print();
    }
}
pair<Point, Point> closestPoints(Point* points, int numPoints) {
    int minimum=INT_MAX;
    Point x, y;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i+1; j < numPoints; ++j) {
            if (distance(points[i], points[j])<minimum) {
                minimum=distance(points[i], points[j]);
                x=points[i];
                y=points[j];
            }

        }
    }
    return make_pair(x, y);
}
pair<Point, Point> farthestPoints(Point* points, int numPoints) {
    int maximum=INT_MIN;
    Point x, y;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i+1; j < numPoints; ++j) {
            if (distance(points[i], points[j])>maximum) {
                maximum=distance(points[i], points[j]);
                x=points[i];
                y=points[j];
            }

        }
    }
    return make_pair(x, y);
}
void sortPoints(Point* points, int numPoints) {
    sort(points,points+numPoints, [](const Point &a,const Point &b){return b.getX()>a.getX();});
}

