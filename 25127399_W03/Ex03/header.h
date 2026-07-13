#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class MyIntArray{
    private:
        int* arr;
        int n;

    public:
        MyIntArray();

        MyIntArray(int* arr, int n);

        MyIntArray(const MyIntArray& other);

        MyIntArray& operator=(const MyIntArray& other);

        MyIntArray(string str);

        string to_String();

        MyIntArray clone();

        void output();
        
        ~MyIntArray();
};

#endif