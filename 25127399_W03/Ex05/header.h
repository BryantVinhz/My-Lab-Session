#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Theater{
    private:
        vector<vector<char>> seats;
        vector<double> prices;
        double total_money;
        int total_tickets;

    public:
        Theater();

        void set_Prices();

        void output_map();

        void buy_Tickets();

        void sales();

        void stats();
};


#endif