#include "header.h"
using namespace std;

int main(){
    Theater t;

    int choice;

    t.set_Prices();

    do{
        cout << "=========MENU=========" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Map" << endl;
        cout << "2. Buy Ticket" << endl;
        cout << "3. Revenue" << endl;
        cout << "4. Statistic" << endl;
        cout << "======================" << endl;

        cout << "Choice: ";
        cin >> choice;

        if(choice == 0) break;
        else if(choice == 1){
            t.output_map();
        }
        else if(choice == 2){
            t.buy_Tickets();
        }
        else if(choice == 3){
            t.sales();
        }
        else t.stats();

        if(choice < 0 || choice > 4){
            cout << "Invalid - Nhập lại lựa chọn" << endl;
        }
    }while(choice != 0);

    return 0;
}