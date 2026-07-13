#ifndef HEADER_2_H
#define HEADER_2_H

#include "../Ex01/header_1.h"
#include <vector>

class Triangle{
    private:
        Point2D A, B, C;

    public:
        Triangle();

        Triangle(const Point2D& A);

        Triangle(const Point2D& A, const Point2D& B, const Point2D& C);

        Triangle(int xA, int yA, int xB, int yB, int xC, int yC);

        Triangle(const Triangle &other);

        Triangle(string str);

        string to_String();

        Triangle clone();

        void output();

        ~Triangle();
};



#endif