#include "header_1.h"
using namespace std;

int main(){
    Point2D p1;
    p1.output();
    cout << "====================" << endl;

    Point2D p2(7);
    p2.output();
    cout << "====================" << endl;

    Point2D p3(-1, 2);
    p3.output();
    cout << "====================" << endl;

    Point2D p4 = p3;
    p4.output();
    cout << "====================" << endl;

    cout << "To String: " << p4.to_String() << endl;
    cout << "====================" << endl;
    
    Point2D p5("12,-6");
    p5.output();
    cout << "====================" << endl;
    
    Point2D p6 = p5.clone();
    p6.output();
    return 0;
}