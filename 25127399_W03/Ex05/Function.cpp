#include "header.h"
using namespace std;

Theater :: Theater(){
    seats = vector<vector<char>>(15, vector<char>(30, '#'));
    prices = vector<double>(15);
    total_money = 0.0;
    total_tickets = 0;
}

void Theater :: output_map(){
    cout << "=====SEATS=====" << endl;
    cout << "       1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0" << endl;
    for(int i = 0; i < 15; i++){
        cout << "Rows " << i+1 << " ";
        for(int j = 0; j < 30; j++){
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

void Theater :: set_Prices(){
    for(int i = 0; i < 15; i++){
        int price;
        do{
            cout << "Ticket price for row " << i+1 << ": ";
            cin >> price;
            if(price < 0){
                cout << "Invalid - Re-enter ticket price for this row" << endl;
            }
        }while(price < 0);

        prices[i] = price;
    }
}

void Theater :: buy_Tickets(){
    int count;
    do{
        cout << "Enter number of tickets: ";
        cin >> count;
    } while (count <= 0);

    double total_group = 0;

    while(count--){
        int row, seat;

        while(1){
            do{
                cout << "Enter row: ";
                cin >> row;
                if(row < 1 || row > 15){
                    cout << "Invalid - Re-enter row" << endl;
                }
            }while(row < 1 || row > 15);

            do{
                cout << "Enter seat number: ";
                cin >> seat;
                if(seat < 1 || seat > 30){
                    cout << "Invalid - Re-enter seat number" << endl;
                }
            }while(seat < 1 || seat > 30);

            int idx1 = row - 1;
            int idx2 = seat - 1;

            if(seats[idx1][idx2] == '#'){
                seats[idx1][idx2] = '*';

                double price_x = prices[idx1];

                total_money += price_x;
                total_group += price_x;
                total_tickets++;
                break;
            }

            cout << "Seat already booked - Choose again" << endl;
        }
    }

    cout << "Total payment: " << total_group << endl;

    output_map();
}

void Theater :: sales(){
    cout << "=====REVENUE=====" << endl;
    cout << "Total revenue: " << total_money << endl;
}

void Theater :: stats(){
    cout << "=====STATISTICS=====" << endl;
    cout << "Tickets sold: " << total_tickets << endl;
    cout << "Available seats: " << 15*30 - total_tickets << endl;
    cout << "=====DETAILS=====" << endl;
    
    for(int i = 0; i < 15; i++){
        int sum = 0;
        for(int j = 0; j < 30; j++){
            if(seats[i][j] == '#'){
                sum++;
            }
        }
        cout << "Row " << i+1 << " has " << sum << " available seats" << endl;
    }
}
