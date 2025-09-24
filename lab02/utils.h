//
// Created by denes on 2025. 09. 24..
//

#ifndef LAB2_UTILS_H
#define LAB2_UTILS_H
#include <utility>

#include "points.h"
double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point&
d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);

std::pair<Point, Point> closestPoints(Point* points, int numPoints);

std::pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
#endif //LAB2_UTILS_H