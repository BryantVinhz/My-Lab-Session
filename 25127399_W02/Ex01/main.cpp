#include "Fraction.h"
using namespace std;

int main(){
    Fraction a;
    Fraction b;

    cout << "Input A: " << endl;
    a.input();
    cout << "Input B: " << endl;
    b.input();

    int choice;

    do{
            cout << "===============LIST===============" << endl;
            cout << "0. Exit" << endl;
            cout << "1. Add 2 fractions" << endl;
            cout << "2. Subtract 2 fractions" << endl;
            cout << "3. Multiply 2 fractions" << endl;
            cout << "4. Divide 2 fractions" << endl;
            cout << "5. Reduce fraction" << endl;
            cout << "6. Compare 2 fractions" << endl;
            cout << "7. Check fraction is positive?" << endl;
            cout << "8. Check fraction is negative" << endl;
            cout << "9. Check fraction is zero?" << endl;
            cout << "==================================" << endl;

            cout << "Input the choice (from 0 to 9): ";
            cin >> choice;
        if(choice == 0) break;
        
        if(choice == 1){
            Fraction ans = a.add(b);
            cout << "Fraction A add Fraction B: ";
            ans.output();
        }
        else if(choice == 2){
            cout << "a: Fraction A minus Fraction B" << endl;
            cout << "b: Fraction B minus Fraction A" << endl;
            cout << "Choose (from a to b): ";
            string str;
            cin >> str;
            if(str == "a"){
                Fraction ans = a.subtract(b);
                cout << "Fraction A minus Fraction B: ";
                ans.output();
            }
            else{
                Fraction ans = b.subtract(a);
                cout << "Fraction B minus Fraction A: ";
                ans.output();
            }
        }
        else if(choice == 3){
            Fraction ans = a.multiply(b);
            cout << "Fraction A times Fraction B: ";
            ans.output();
        }
        else if(choice == 4){
            cout << "a: Fraction A divide Fraction B" << endl;
            cout << "b: Fraction B divide Fraction A" << endl;
            cout << "Choose (from a to b): ";
            string str;
            cin >> str;
            try{
                if(str == "a"){
                    Fraction ans = a.divide(b);
                    cout << "Fraction A divide Fraction B: ";
                    ans.output();
                }
                else{
                    Fraction ans = b.divide(a);
                    cout << "Fraction B divide Fraction A: ";
                    ans.output();
                }
            }
            catch (const char* message){
                cout << "Error: " << message << endl;
            }
        }
        else if(choice == 5){
            cout << "a: Reduce Fraction A" << endl;
            cout << "b: Reduce Fraction B" << endl;
            cout << "Choose (from a to b): ";
            string str;
            cin >> str;
            if(str == "a"){
                Fraction ans = a.reduce();
                cout << "Reduce Fraction A: ";
                ans.output();
            }
            else{
                Fraction ans = b.reduce();
                cout << "Reduce Fraction B: ";
                ans.output();
            }
        }
        else if(choice == 6){
            cout << "Compare Fraction A and Fraction B: " << a.compare(b) << endl;
        }
        else if(choice == 7){
            cout << "a: Check Fraction A is positive" << endl;
            cout << "b: Check Fraction B is positive" << endl;
            cout << "Choose (from a to b): ";
            string str;
            cin >> str;
            if(str == "a"){
                bool check = a.isPositive();
                cout << "Check Fraction A: ";
                if(check == true) cout << "A is positive" << endl;
                else cout << "A is not positive" << endl;
            } 
            else{
                bool check = b.isPositive();
                cout << "Check Fraction B: ";
                if(check == true) cout << "B is positive" << endl;
                else cout << "B is not positive" << endl;
            }
        }
        else if(choice == 8){
            cout << "a: Check Fraction A is negative" << endl;
            cout << "b: Check Fraction b is negative" << endl;
            cout << "Choose (from a to b): ";
            string str;
            cin >> str;
            if(str == "a"){
                bool check = a.isNegative();
                cout << "Check Fraction A: ";
                if(check == true) cout << "A is negative" << endl;
                else cout << "A is not negative" << endl;
            } 
            else{
                bool check = b.isNegative();
                cout << "Check Fraction B: ";
                if(check == true) cout << "B is negative" << endl;
                else cout << "B is not negative" << endl;
            }
        }
        else if(choice == 9){
            cout << "a: Check Fraction A is zero" << endl;
            cout << "b: Check Fraction b is zero" << endl;
            cout << "Choose (from a to b): ";
            string str;
            cin >> str;
            if(str == "a"){
                bool check = a.isZero();
                cout << "Check Fraction A: ";
                if(check == true) cout << "A is zero" << endl;
                else cout << "A is not zero" << endl;
            } 
            else{
                bool check = b.isZero();
                cout << "Check Fraction B: ";
                if(check == true) cout << "B is zero" << endl;
                else cout << "B is not zero" << endl;
            }
        }
    }while(choice != 0);
    return 0;
}