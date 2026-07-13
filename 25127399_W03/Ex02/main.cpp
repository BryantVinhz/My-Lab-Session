#include "header_2.h"

using namespace std;

int main(){
    Point2D A(1, 2);
    Point2D B(3, 4);
    Point2D C(5, 6);

    Triangle T1;
    T1.output();
    cout << "====================" << endl;

    Triangle T2(A, B, C);
    T2.output();
    cout << "====================" << endl;

    Triangle T3(9, -8, 7, 6, -5, 4);
    T3.output();
    cout << "====================" << endl;

    Triangle T4 = T3;
    T4.output();
    cout << "====================" << endl;

    cout << "To String: " << T4.to_String() << endl;
    cout << "====================" << endl;
    
    Triangle T5("(-10, 20);(30, 40);(50, -60)");
    T5.output();
    cout << "====================" << endl;

    Triangle T6 = T5.clone();
    T6.output();

    return 0;
}