#include "header.h"
using namespace std;

//Default Constructor
Fraction :: Fraction() : num(0), deno(1){}

//Paremeter Constructor
Fraction :: Fraction(int num, int deno) : num(num), deno(deno){
    simplify();
}

//Copy Constructor
Fraction :: Fraction(const Fraction& other){
    this->num = other.num;
    this->deno = other.deno;
}

//Assignment Operator
Fraction& Fraction :: operator=(const Fraction& other){
    if(this != &other){
        this->num = other.num;
        this->deno = other.deno;
    }
    return *this;
}

//Simplify Fraction
int Fraction :: gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

Fraction& Fraction :: simplify(){
    int val = gcd(num, deno);
    num /= val;
    deno /= val;

    if(deno < 0){
        num = -num;
        deno = -deno;
    }
    return *this;
}

//F = Fx +/-/*// Fy
Fraction Fraction :: operator+(const Fraction& other){
    Fraction tmp;
    tmp.deno = this->deno * other.deno;
    tmp.num = this->num * other.deno + other.num * this->deno;
    return tmp.simplify();
}

Fraction Fraction :: operator-(const Fraction& other){
    Fraction tmp;
    tmp.deno = this->deno * other.deno;
    tmp.num = this->num * other.deno - other.num * this->deno;
    return tmp.simplify();
}

Fraction Fraction :: operator*(const Fraction& other){
    Fraction tmp;
    tmp.num = this->num * other.num;
    tmp.deno = this->deno * other.deno;
    return tmp.simplify();
}

Fraction Fraction :: operator/(const Fraction& other){
    Fraction tmp;
    tmp.num = this->num * other.deno;
    tmp.deno = this->deno * other.num;
    return tmp.simplify();
}

//Comparison
bool Fraction :: operator==(const Fraction& other){
    if(this->num * other.deno == this->deno * other.num) return true;
    return false;
}

bool Fraction :: operator!=(const Fraction& other){
    if(this->num * other.deno != this->deno * other.num) return true;
    return false;
}

bool Fraction :: operator>=(const Fraction& other){
    if(this->num * other.deno >= this->deno * other.num) return true;
    return false;
}

bool Fraction :: operator>(const Fraction& other){
    if(this->num * other.deno > this->deno * other.num) return true;
    return false;
}

bool Fraction :: operator<=(const Fraction& other){
    if(this->num * other.deno <= this->deno * other.num) return true;
    return false;
}

bool Fraction :: operator<(const Fraction& other){
    if(this->num * other.deno < this->deno * other.num) return true;
    return false;
}

//Fx = Fy +/-/*// z
Fraction Fraction :: operator+(int x){
    Fraction tmp;
    tmp.deno = this->deno;
    tmp.num = this->num + x * this->deno;
    return tmp.simplify();
}


Fraction Fraction :: operator-(int x){
    Fraction tmp;
    tmp.deno = this->deno;
    tmp.num = this->num - x * this->deno;
    return tmp.simplify();
}

Fraction Fraction :: operator*(int x){
    Fraction tmp;
    tmp.deno = this->deno;
    tmp.num = this->num * x;
    return tmp.simplify();
}
Fraction Fraction :: operator/(int x){
    Fraction tmp;
    tmp.num = this->num;
    tmp.deno = this->deno * x;
    return tmp.simplify();
}

//Fx = z +/-/*// Fy
Fraction operator+(int x, const Fraction& other){
    Fraction tmp;
    tmp.deno = other.deno;
    tmp.num = x * other.deno + other.num;
    return tmp.simplify();
}

Fraction operator-(int x, const Fraction& other){
    Fraction tmp;
    tmp.deno = other.deno;
    tmp.num = x * other.deno - other.num;
    return tmp.simplify();
}

Fraction operator*(int x, const Fraction& other){
    Fraction tmp;
    tmp.num = x * other.num;
    tmp.deno = other.deno;
    return tmp.simplify();
}

Fraction operator/(int x, const Fraction& other){
    Fraction tmp;
    tmp.num = x * other.deno;
    tmp.deno = other.num;
    return tmp.simplify();
}

//Output operator
ostream& operator<<(ostream& out, const Fraction& other){
    out << "Fraction: " << other.num << " / " << other.deno << endl;
    return out;
}

//f1 += f2 
Fraction& Fraction :: operator+=(const Fraction& other){
    int num_tmp = this->num * other.deno + this->deno * other.num;
    int deno_tmp = this->deno * other.deno;

    this->num = num_tmp;
    this->deno = deno_tmp;

    this->simplify();
    return *this;
}

//f1 -= f2
Fraction& Fraction :: operator-=(const Fraction& other){
    int num_tmp = this->num * other.deno - this->deno * other.num;
    int deno_tmp = this->deno * other.deno;

    this->num = num_tmp;
    this->deno = deno_tmp;
    
    this->simplify();
    return *this;
}

//f1 *= f2
Fraction& Fraction :: operator*=(const Fraction& other){
    int num_tmp = this->num * other.num;
    int deno_tmp = this->deno * other.deno;

    this->num = num_tmp;
    this->deno = deno_tmp;

    this->simplify();
    return *this;
}

//f1 /= f2
Fraction& Fraction :: operator/=(const Fraction& other){
    int num_tmp = this->num * other.deno;
    int deno_tmp = this->deno * other.num;

    this->num = num_tmp;
    this->deno = deno_tmp;

    this->simplify();
    return *this;
}

//Prefix and Postfix Operator
Fraction& Fraction :: operator++(){
    this->num += this->deno;
    return *this;
}


Fraction Fraction :: operator++(int){
    Fraction tmp = *this;
    this->num += this->deno;
    return tmp;
}


Fraction& Fraction :: operator--(){
    this->num -= this->deno;
    return *this;
}


Fraction Fraction :: operator--(int){
    Fraction tmp = *this;
    this->num -= this->deno;
    return tmp;
}

//Typecasting
Fraction :: operator float(){
    return (float)this->num / (float)this->deno;
}