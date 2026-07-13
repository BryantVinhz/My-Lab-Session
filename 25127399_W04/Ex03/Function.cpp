#include "header.h"
using namespace std;

//Default Constructor
IntArray :: IntArray() : arr(nullptr), n(0){}

//1 Parameter Constructor
IntArray :: IntArray(int n) : n(n){
    this->arr = new int[n]{0};
}

//2 Parameters Constructor
IntArray :: IntArray(int *arr, int n){
    this->n = n;
    this->arr = new int[this->n];

    for(int i = 0; i < this->n; i++){
        this->arr[i] = arr[i];
    }
}

//Copy Constructor
IntArray :: IntArray(const IntArray& other){
    this->n = other.n;
    this->arr = new int[this->n];

    for(int i = 0; i < this->n; i++){
        this->arr[i] = other.arr[i];
    }
}

//Assignment Operator
IntArray& IntArray :: operator=(const IntArray& other){
    if(this != &other){
        delete []this->arr;
        this->n = other.n;
        this->arr = new int[this->n];

        for(int i = 0; i < this->n; i++){
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

//Ostream & Istream
istream& operator>>(istream& in, IntArray& other){
    in >> other.n;
    other.arr = new int[other.n];
    
    for(int i = 0; i < other.n; i++){
        in >> other.arr[i];
    }

    return in;
}

ostream& operator<<(ostream& out, const IntArray& other){
    out << "N: " << other.n << endl;
    out << "Array: ";
    for(int i = 0; i < other.n; i++){
        out << other.arr[i] << " ";
    }

    return out;
}

//Operator []
int& IntArray :: operator[](int idx){
    return arr[idx];
}

const int& IntArray :: operator[](int idx) const{
    return arr[idx];
}

//Typecasting
IntArray :: operator int(){
    return this->n;
}

//Destructor
IntArray :: ~IntArray(){
    delete[] this->arr;
    this->n = 0;
    this->arr = nullptr;
}