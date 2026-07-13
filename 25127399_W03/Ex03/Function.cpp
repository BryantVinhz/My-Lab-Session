#include "header.h"
using namespace std;

//Defaults Constructor
MyIntArray :: MyIntArray() : arr(nullptr), n(n){
    cout << "MyIntArray::Default cons" << endl;
}


//2 Parameters Constructor
MyIntArray :: MyIntArray(int *arr, int n){
    this->n = n;
    this->arr = new int[n];
    for(int i = 0; i < this->n; i++){
        this->arr[i] = arr[i];
    }
    cout << "MyIntArray::2 parameters cons" << endl;
}

//Copy Constructor
MyIntArray :: MyIntArray(const MyIntArray& other){
    this->n = other.n;
    this->arr = new int[this->n];

    for(int i = 0; i < this->n; i++){
        this->arr[i] = other.arr[i];
    }
    cout << "MyIntArray::Copy cons" << endl;
}

//Assigment Operator
MyIntArray& MyIntArray :: operator=(const MyIntArray& other){
    if(this != &other){
        delete [] this->arr;
        this->n = other.n;
        this->arr = new int[this->n];
        for(int i = 0; i < this->n; i++){
            this->arr[i] = other.arr[i];
        }
    }
    cout << "MyIntArray::Assignment Operator" << endl;
    return *this;
}

//String Constructor
MyIntArray :: MyIntArray(string str){
    string tmp = "";
    vector<int> v;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            v.push_back(stoi(tmp));
            tmp = "";
        }
        else{
            tmp += str[i];
        }
    }

    if(!tmp.empty()){
        v.push_back(stoi(tmp));
    }

    this->n = v.size();

    this->arr = new int[this->n];

    for(int i = 0; i < this->n; i++){
        this->arr[i] = v[i];
    }
    cout << "MyIntArray::String cons" << endl;
}

//to_string method
string MyIntArray :: to_String(){
    string str = "";
    for(int i = 0; i < n; i++){
        str += to_string(arr[i]);
        if(i != n-1){
            str += " ";
        }
    }
    return str;
}

//clone method
MyIntArray MyIntArray :: clone(){
    return MyIntArray(*this);
}

//output method
void MyIntArray :: output(){
    cout << "N: " << n << endl;

    cout << "Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Destructor
MyIntArray :: ~MyIntArray(){
    n = 0;
    delete [] arr;
    arr = nullptr;
    cout << "MyIntArray::Destructor" << endl;
}

