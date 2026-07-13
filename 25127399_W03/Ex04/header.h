#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>
using namespace std;

class student{
    private:
        int id;
        char* fullname;
        char* address;
        double gpa;

    public:
        student();

        student(int id, const char* fullname, const char* address, double gpa);

        student(const student& other);

        student& operator=(const student& other);

        student(string str);

        void set_id(int id);
        int get_id();

        void set_fullname(const char* fullname);
        char* get_fullname();

        void set_address(const char* address);
        char* get_address();

        void set_gpa(double gpa);
        double get_gpa();   

        string to_String();
        student clone();

        void output();
        
        ~student();

};

#endif