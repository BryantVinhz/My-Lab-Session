#include "Point.h"
using namespace std;

Point :: Point(){
}

Point :: Point(float x, float y){
    this->x = x;
    this->y = y;
}

float Point :: get_x(){
    return x;
}

void Point :: set_x(float x){
    this->x = x;
}

float Point :: get_y(){
    return y;
}

void Point :: set_y(float y){
    this->y = y;
}


float Point :: dist_a_b(const Point &other){
    float px = x - other.x;
    float py = y - other.y;
    return  sqrt(pow(px, 2) + pow(py, 2));
}


float Point :: dist_ox(){
    return abs(y);
}

float Point :: dist_oy(){
    return abs(x);
}

void Point :: input(){
    cin >> x >> y;
}

void Point :: output(){
    cout << "(" << x << ", " << y << ")";
}