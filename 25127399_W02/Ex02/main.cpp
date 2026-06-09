#include "Point.h"
#include "Triangle.h"

using namespace std;

int main(){
    Point a;
    Point b;
    Point c;
    cout << "Enter the coordinates x, y: ";
    
    cout << "Input A: ";
    a.input();
    cout << "Input B: ";
    b.input();
    cout << "Input C: ";
    c.input();

    Triangle T(a, b, c);

    int choice;

    do{
        cout << "===============LIST===============" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Distance from Point X to Point Y" << endl;
        cout << "2. Distance from Point X to Ox" << endl;
        cout << "3. Distance from Point X to Oy" << endl;
        cout << "4. Check Valid Triangle" << endl;
        cout << "5. Type of a Triangle" << endl;
        cout << "6. The Perimeter of the Triangle" << endl;
        cout << "7. The Area of the Triangle" << endl;
        cout << "8. The Center G of the Triangle" << endl;
        cout << "9. New Input" << endl;
        cout << "==================================" << endl;

        cout << "Input the choice (from 0 to 9): ";
        cin >> choice;
        if(choice == 0) break;
        
        if(choice == 1){
            cout << "a: Distance from point A to point B" << endl;
            cout << "b: Distance from point A to point C" << endl;
            cout << "c: Distance from point B to point C" << endl;
            cout << "Choose (from a to c): ";
            string str;
            cin >> str;
            if(str == "a"){
                float dist = a.dist_a_b(b);
                cout << "Distance from point A to point B: " << dist << endl;
            }
            else if(str == "b"){
                float dist = a.dist_a_b(c);
                cout << "Distance from point A to point C: " << dist << endl;
            }
            else{
                float dist = b.dist_a_b(c);
                cout << "Distance from point B to point C: " << dist << endl;
            }
        }
        else if(choice == 2){
            cout << "a: Distance from Point A to Ox" << endl;
            cout << "b: Distance from Point B to Ox" << endl;
            cout << "c: Distance from Point C to Ox" << endl;
            cout << "Choose (from a to c): ";
            string str;
            cin >> str;
            if(str == "a"){
                float dist_ox1 = a.dist_ox();
                cout << "Distance from A to Ox: " << dist_ox1 << endl;
            }
            else if(str == "b"){
                float dist_ox1 = b.dist_ox();
                cout << "Distance from B to Ox: " << dist_ox1 << endl;
            }
            else if(str == "c"){
                float dist_ox1 = c.dist_ox();
                cout << "Distance from C to Ox: " << dist_ox1 << endl;
            }
        }
        else if(choice == 3){
            cout << "a: Distance from Point A to Oy" << endl;
            cout << "b: Distance from Point B to Oy" << endl;
            cout << "c: Distance from Point C to Oy" << endl;
            cout << "Choose (from a to c): ";
            string str;
            cin >> str;
            if(str == "a"){
                float dist_oy1 = a.dist_oy();
                cout << "Distance from A to Oy: " << dist_oy1 << endl;
            }
            else if(str == "b"){
                float dist_oy1 = b.dist_oy();
                cout << "Distance from B to Oy: " << dist_oy1 << endl;
            }
            else if(str == "c"){
                float dist_oy1 = c.dist_oy();
                cout << "Distance from C to Oy: " << dist_oy1 << endl;
            }
        }
        else if(choice == 4){
            if(T.is_Valid_Triangle()){
                cout << "This is a Triangle" << endl;
            }
        }
        else if(choice == 5){
            if(T.is_Valid_Triangle()){
                string triangle = T.type_of_triangle();
                cout << "This is " << triangle << endl;
            }
            else cout << "Not a Triangle" << endl;
        }
        else if(choice == 6){
            if(T.is_Valid_Triangle()){
                float p = T.perimeter();
                cout << "The perimeter of the Triangle: " << p << endl;
            }
            else cout << "Not a Triangle" << endl;
        }
        else if(choice == 7){
            if(T.is_Valid_Triangle()){
                float s = T.area();
                cout << "The area of the Triangle: " << s << endl;
            }
            else cout << "Not a Triangle" << endl;
        }
        else if(choice == 8){
            if(T.is_Valid_Triangle()){
                Point G(T.center());
                cout << "The Center G of the Triangle: " << endl;
                G.output();
            }
            else cout << "Not a Triangle" << endl;
        }
        else if(choice == 9){
            cout << "Input new A: ";
            a.input();
            cout << "Input new B: ";
            b.input();
            cout << "Input new C: ";
            c.input();
            
            T = Triangle(a, b, c); 
        }
    }while(choice != 0);

    return 0;
}