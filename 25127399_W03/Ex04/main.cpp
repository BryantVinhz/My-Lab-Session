#include "header.h"
using namespace std;

int main(){
    student a;
    a.output();
    cout << "====================" << endl;

    student b(1001, "Tran Vinh Hung", "TPHCM", 3.8);
    b.output();
    cout << "====================" << endl;

    cout << "To String: " << b.to_String() << endl;
    cout << "====================" << endl;

    student c = b;
    c.output();
    cout << "====================" << endl;

    student d(1002, "Tran Vinh Kiet", "HN", 2.9);
    student e;
    e = d;
    e.output();
    cout << "====================" << endl;

    student f("1003 - Trinh Thi Thu Huong - HN - 4.0");
    f.output();
    cout << "====================" << endl;

    student h = f.clone();
    h.output();

    return 0;
}