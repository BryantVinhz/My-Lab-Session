#ifndef HEADER_1_H
#define HEADER_1_H

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Point2D{
    private:
        int x, y;

    public:
        Point2D();

        Point2D(int x);

        Point2D(int x, int y);

        Point2D(const Point2D &other);

        Point2D(string str);

        void set_x(int x);
        int get_x();

        void set_y(int y);
        int get_y();

        string to_String();

        Point2D clone();

        void output();

        ~Point2D();
};

#endif 