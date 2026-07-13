#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class IntArray{
    private:
        int* arr;
        int n;

    public:
        IntArray();

        IntArray(int n);

        IntArray(int *arr, int n);

        IntArray(const IntArray& other);

        IntArray& operator=(const IntArray& other);

        friend istream& operator>>(istream& in, IntArray& other);
        friend ostream& operator<<(ostream& out, const IntArray& other);

        int& operator[](int idx);
        const int& operator[](int idx) const;

        operator int();

        ~IntArray();
};


#endif