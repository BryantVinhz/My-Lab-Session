#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <cmath>


class Point{
private:
    float x, y;

public:
    Point();
    Point(float x, float y);

    float get_x();
    void set_x(float x);

    float get_y();
    void set_y(float y);

    float dist_a_b(const Point &other);
    float dist_ox();
    float dist_oy();

    void input();
    void output();
};

#endif