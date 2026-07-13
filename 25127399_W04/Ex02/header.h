#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Date{
    private:
        int day, month, year;

    public:
        Date();

        Date(int year);

        Date(int year, int month);

        Date(int year, int month, int day);

        Date (const Date& other);

        Date& operator=(const Date& other);

        Date Tomorrow();
        Date Yesterday();

        bool operator==(const Date& other);
        bool operator!=(const Date& other);
        bool operator>=(const Date& other);
        bool operator<=(const Date& other);
        bool operator>(const Date& other);
        bool operator<(const Date& other);

        Date operator+(int x);
        Date operator-(int x);

        Date& operator++();
        Date operator++(int);

        Date& operator--();
        Date operator--(int);

        friend ostream& operator<<(ostream& out, const Date& other);
        friend istream& operator>>(istream& in, Date& other);

        Date& operator+=(int x);
        Date& operator-=(int x);

        operator int();
        operator long();
};

#endif