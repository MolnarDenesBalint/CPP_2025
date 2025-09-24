//
// Created by denes on 2025. 09. 24..
//

#ifndef CPP_2024_POINTS_H
#define CPP_2024_POINTS_H
class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
};
#endif //CPP_2024_POINTS_H