#include "Fraction.h"

using namespace std;

Fraction :: Fraction(){}

Fraction :: Fraction(int num, int deno){
    this->num = num;
    this->deno = deno;
}

int Fraction :: get_num(){
    return num;
}

void Fraction :: set_num(int num){
    this->num = num;
}

int Fraction :: get_deno(){
    return deno;
}

void Fraction :: set_deno(int deno){
    this->deno = deno;
}

int Fraction :: gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

Fraction Fraction :: reduce(){
    int val = gcd(num, deno);
    int num_tmp = num / val;
    int deno_tmp = deno / val;

    if(deno_tmp < 0){
        num_tmp = -num_tmp;
        deno_tmp = -deno_tmp;
    }
    return Fraction(num_tmp, deno_tmp);
}

Fraction Fraction :: add(const Fraction &other){
    int deno_tmp = this->deno * other.deno;
    int num_tmp = this->num * other.deno + other.num * this->deno;

    Fraction ans(num_tmp, deno_tmp);
    return ans.reduce();
}

Fraction Fraction :: subtract(const Fraction &other){
    int deno_tmp = this->deno * other.deno;
    int num_tmp = this->num * other.deno - other.num * this->deno;

    Fraction ans(num_tmp, deno_tmp);
    return ans.reduce();
}

Fraction Fraction :: multiply(const Fraction &other){
    int num_tmp = this->num * other.num;
    int deno_tmp = this->deno * other.deno;

    Fraction ans(num_tmp, deno_tmp);
    return ans.reduce();
}

Fraction Fraction :: divide(const Fraction &other){
    if(other.num == 0){
        throw "Divided by Zero";
    }
    int num_tmp = this->num * other.deno;
    int deno_tmp = this->deno * other.num;

    Fraction ans(num_tmp, deno_tmp);
    return ans.reduce();
}

string Fraction :: compare(Fraction other){
    string str = "";
    Fraction tmp_1 = this->reduce();
    Fraction tmp_2 = other.reduce();
    
    int val_1 = tmp_1.num * tmp_2.deno;
    int val_2 = tmp_1.deno * tmp_2.num;

    if(val_1 == val_2){
        str = "Fraction A is equal Fraction B";
    }
    else if(val_1 > val_2){
        str = "Fraction A is larger then Fraction B";
    }
    else str = "Fraction B is larger than Fraction A";
    return str;
}

bool Fraction :: isPositive(){
    if(this->num * this->deno > 0) return true;
    return false;
}

bool Fraction :: isNegative(){
    if(this->num * this->deno < 0) return true;
    return false;
}

bool Fraction :: isZero(){
    if(this->num == 0 && this->deno != 0) return true;
    return false;
}

void Fraction :: input(){
    cout << "Enter Numerator: ";
    cin >> num;
    do{
        cout << "Enter Denominator: ";
        cin >> deno;
        if(deno == 0){
            cout << "Re-enter Denominator" << endl;
        }
    }while(deno == 0);
}

void Fraction :: output(){
    cout << num << " " << deno << endl;
}