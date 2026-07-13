#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

class Fraction{
    private:
        int num, deno;
    
    public:
        Fraction();

        Fraction(int num, int deno);

        Fraction(const Fraction& other);

        Fraction& operator=(const Fraction& other);

        int gcd(int a, int b);
        Fraction& simplify();

        Fraction operator+(const Fraction& other);
        Fraction operator-(const Fraction& other);
        Fraction operator*(const Fraction& other);
        Fraction operator/(const Fraction& other);

        bool operator==(const Fraction& other);
        bool operator!=(const Fraction& other);
        bool operator>=(const Fraction& other);
        bool operator>(const Fraction& other);
        bool operator<=(const Fraction& other);
        bool operator<(const Fraction& other);

        Fraction operator+(int x);
        Fraction operator-(int x);
        Fraction operator*(int x);
        Fraction operator/(int x);

        friend Fraction operator+(int x, const Fraction& other);
        friend Fraction operator-(int x, const Fraction& other);
        friend Fraction operator*(int x, const Fraction& other);
        friend Fraction operator/(int x, const Fraction& other);

        friend ostream& operator<<(ostream& out, const Fraction& other);

        Fraction& operator+=(const Fraction& other);
        Fraction& operator-=(const Fraction& other);
        Fraction& operator*=(const Fraction& other);
        Fraction& operator/=(const Fraction& other);

        Fraction& operator++();
        Fraction operator++(int);

        Fraction& operator--();
        Fraction operator--(int);

        operator float();
};
#endif