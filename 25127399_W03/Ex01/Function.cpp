#include "header_1.h"
using namespace std;

//Constructor method
Point2D :: Point2D() : x(0), y(0){
    cout << "Point2D::Default cons" << endl;
}

Point2D :: Point2D(int x) : x(x), y(0){
    cout << "Point2D::1 parameter cons" << endl;
}

Point2D :: Point2D(int x, int y) : x(x), y(y){
    cout << "Point2D::2 parameter cons" << endl;
}

Point2D :: Point2D(const Point2D &other){
    this->x = other.x;
    this->y = other.y;
    cout << "Point2D::Copy cons" << endl;
}

//"1,-2"
Point2D :: Point2D(string str){
    int key = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ','){
            key = i;
            break;
        }
    }

    string tmp_x = "";
    string tmp_y = "";

    for(int i = 0; i < key; i++){
        tmp_x += str[i];
    }
    
    for(int i = key+1; i < str.size(); i++){
        tmp_y += str[i];
    }

    this->x = stoi(tmp_x);
    this->y = stoi(tmp_y);

    cout << "Point2D::String cons" << endl;
}

//Set X method
void Point2D :: set_x(int x){
    this->x = x;
}

//Get X method
int Point2D :: get_x(){
    return x;
}

//Set Y method
void Point2D :: set_y(int y){
    this->y = y;
}

//Get Y method
int Point2D :: get_y(){
    return y;
}

//to_string method
string Point2D :: to_String(){
    return "(" + to_string(x) + "," + to_string(y) + ")";
}

//clone method
Point2D Point2D :: clone(){
    cout << "Point2D::Clone" << endl;
    return Point2D(*this);
}

//output method
void Point2D :: output(){
    cout << "X: " << x << " and Y: " << y << endl;
}

//Destructor method
Point2D :: ~Point2D(){
    cout << "Point2D::Destructor" << endl;
}
