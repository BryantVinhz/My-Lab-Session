#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

using namespace std;

class Triangle{
private:
    Point A, B, C;
    float edge1, edge2, edge3;

    void compute_edge();

public:
    Triangle();
    Triangle(Point A, Point B, Point C);

    bool is_Valid_Triangle();
    string type_of_triangle();

    float perimeter();
    float area();
    Point center();

    void input();
    void output();
};

#endif