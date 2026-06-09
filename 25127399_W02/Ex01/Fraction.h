#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Fraction{
    private:
        int num, deno;

    public:
        Fraction();

        Fraction(int num, int deno);

        int get_num();
        void set_num(int num);

        int get_deno();
        void set_deno(int deno);

        int gcd(int a, int b);

        Fraction add(const Fraction &other);
        Fraction subtract(const Fraction &other);
        Fraction multiply(const Fraction &other);
        Fraction divide(const Fraction &other);

        Fraction reduce();

        string compare(Fraction other);

        bool isPositive();

        bool isNegative();

        bool isZero();

        void input();
        void output();
};

#endif