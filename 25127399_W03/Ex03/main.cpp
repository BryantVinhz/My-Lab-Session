#include "header.h"

int main(){
    MyIntArray a;
    a.output();
    cout << "========================" << endl;

    int n_b = 5;
    int arr_b[n_b] = {1, 2, 3, 4, 5};

    MyIntArray b(arr_b, n_b);
    b.output();
    cout << "========================" << endl;

    cout << "To String: " << b.to_String() << endl;
    cout << "========================" << endl;

    MyIntArray c = b;
    c.output();
    cout << "========================" << endl;

    int n_d = 3;
    int arr_d[n_d] = {10, 21, 12};
    MyIntArray d_1(arr_d, n_d);
    MyIntArray d_2;
    d_2 = d_1;
    d_2.output();
    cout << "========================" << endl;

    string str = "100 21 1 3 5 7 11";
    MyIntArray e(str);
    e.output();
    cout << "========================" << endl;

    MyIntArray f = e.clone();
    f.output();
    cout << "========================" << endl;

    return 0;
}