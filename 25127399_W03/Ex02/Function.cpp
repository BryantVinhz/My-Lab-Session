#include "header_2.h"
using namespace std;

//Constructor
Triangle :: Triangle(){
    cout << "Triangle::Default cons" << endl;
}

Triangle :: Triangle(const Point2D& A, const Point2D& B, const Point2D& C) : A(A), B(B), C(C){
    cout << "Triangle::3 parameters Object cons" << endl;
}

Triangle :: Triangle(int xA, int yA, int xB, int yB, int xC, int yC) : A(xA, yA), B(xB, yB), C(xC, yC){
    cout << "Triangle::6 parameters values cons" << endl;
}

Triangle :: Triangle(const Triangle& other){
    this->A = other.A;
    this->B = other.B;
    this->C = other.C;
    cout << "Triangle::Copy cons" << endl;
}

//  "(1,-2);(3,4);(-5,6)"
Triangle :: Triangle(string str){
    vector<int> v;
    
    string tmp = "";
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == ')' || str[i] == ',' || str[i] == ';'){
            if(!tmp.empty()){
                v.push_back(stoi(tmp));
                tmp = "";   
            }
        }
        else{
            tmp += str[i];
        }
    }

    A = Point2D(v[0], v[1]);
    B = Point2D(v[2], v[3]);
    C = Point2D(v[4], v[5]);

    cout << "Triangle::String cons" << endl;
}

//to_string method
string Triangle :: to_String(){
    string res = "";
    res += "(" + to_string(A.get_x()) + "," + to_string(A.get_y()) + ");";
    res += "(" + to_string(B.get_x()) + "," + to_string(B.get_y()) + ");";
    res += "(" + to_string(C.get_x()) + "," + to_string(C.get_y()) + ")";
    return res;
}

//clone method
Triangle Triangle :: clone(){
    return Triangle(*this);
}

//output method
void Triangle :: output(){
    cout << "Point A: X = " << A.get_x() << " and Y = " << A.get_y() << endl; 
    cout << "Point B: X = " << B.get_x() << " and Y = " << B.get_y() << endl; 
    cout << "Point C: X = " << C.get_x() << " and Y = " << C.get_y() << endl; 
}

//Destructor
Triangle :: ~Triangle(){
    cout << "Triangle::Destructor" << endl;
}