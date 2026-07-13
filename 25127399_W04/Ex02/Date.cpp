#include "header.h"
using namespace std;

//Default Constructor - Current Date
Date :: Date(){
    time_t t = time(0);          // Lấy thời gian hiện tại
    tm* now = localtime(&t);     // Chuyển sang dạng struct tm

    day = now->tm_mday;
    month = now->tm_mon + 1;     // tm_mon từ 0 -> 11 nên +1
    year = now->tm_year + 1900;  // tm_year tính từ 1900 nên +1900
}

//1-Parameter Constructor
Date :: Date(int year) : day(1), month(1), year(year){}

//2-Parameters Constructor
Date :: Date(int month, int year) : day(1), month(month), year(year){}

//3-Parameters Constructor
Date :: Date(int day, int month, int year) : day(day), month(month), year(year){}

//Copy Constructor
Date :: Date(const Date& other){
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

//Assignment Operator
Date& Date :: operator=(const Date& other){
    if(this != &other){
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }
    return *this;
}

//Comparison
bool Date :: operator==(const Date& other){
    if(this->day == other.day && this->month == other.month && this->year == other.year) return true;
    return false;
}

bool Date :: operator!=(const Date& other){
    if(this->day != other.day || this->month != other.month || this->year != other.year) return true;
    return false;
}

bool Date :: operator>=(const Date& other){
    if(this->year > other.year) return true;
    if(this->year < other.year) return false;

    if(this->month > other.month) return true;
    if(this->month < other.month) return false;

    if(this->day >= other.day) return true;
    return false;
}

bool Date :: operator<=(const Date& other){
    if(this->year > other.year) return false;
    if(this->year < other.year) return true;

    if(this->month > other.month) return false;
    if(this->month < other.month) return true;

    if(this->day > other.day) return false;
    return true;
}

bool Date :: operator>(const Date& other){
    if(this->year > other.year) return true;
    if(this->year < other.year) return false;

    if(this->month > other.month) return true;
    if(this->month < other.month) return false;

    if(this->day > other.day) return true;
    return false;
}

bool Date :: operator<(const Date& other){
    if(this->year > other.year) return false;
    if(this->year < other.year) return true;

    if(this->month > other.month) return false;
    if(this->month < other.month) return true;

    if(this->day >= other.day) return false;
    return true;
}

//DateX = DateY +/- Z
bool isLeap(int x){
    if((x % 400 == 0) || (x % 4 == 0 && x % 100 != 0)) return true;
    return false;
}

int day_in_month(int x, int y){
    if(x == 4 || x == 6 || x == 9 || x == 11) return 30;
    if(x == 2){
        if(isLeap(y)) return 29;
        return 28;
    }
    return 31;
}

Date Date :: operator+(int x){
    Date res = *this;

    res.day += x;

    while(res.day > day_in_month(res.month, res.year)){
        res.day -= day_in_month(res.month, res.year);

        res.month++;

        if(res.month > 12){
            res.year++;
            res.month -= 12;
        }
    }

    return res;
}

Date Date :: operator-(int x){
    Date res = *this;

    res.day -= x;

    while(res.day <= 0){
        res.month--;

        if(res.month < 1){
            res.year--;
            res.month = 12;
        }

        res.day += day_in_month(res.month, res.year);
    }

    return res;
}

//Prefix and Postfix Operator
Date& Date :: operator++(){
    this->day += 1;

    while(this->day > day_in_month(this->month, this->year)){
        this->day -= day_in_month(this->month, this->year);

        this->month++;

        if(this->month > 12){
            this->year++;
            this->month -= 12;
        }
    }

    return *this;
}

Date Date :: operator++(int){
    Date tmp = *this;
    
    this->day += 1;

    while(this->day > day_in_month(this->month, this->year)){
        this->day -= day_in_month(this->month, this->year);

        this->month++;

        if(this->month > 12){
            this->year++;
            this->month -= 12;
        }
    }

    return tmp;
}

Date& Date :: operator--(){
    this->day -= 1;

    while(this->day <= 0){
        this->month--;

        if(this->month < 1){
            this->year--;
            this->month = 12;
        }

        this->day += day_in_month(this->month, this->year);
    }

    return *this;
}

Date Date :: operator--(int){
    Date tmp = *this;

    this->day -= 1;

    while(this->day <= 0){
        this->month--;

        if(this->month < 1){
            this->year--;
            this->month = 12;
        }

        this->day += day_in_month(this->month, this->year);
    }

    return tmp;
}

//Ostream & Istream
ostream& operator<<(ostream& out, const Date& other){
    out << "Date: " << other.day << "/" << other.month << "/" << other.year << endl;
    return out; 
}

istream& operator>>(istream& in, Date& other){
    in >> other.day >> other.month >> other.year;
    return in;
}

//Date += / -= x
Date& Date :: operator+=(int x){
    this->day += x;

    while(this->day > day_in_month(this->month, this->year)){
        this->day -= day_in_month(this->month, this->year);

        this->month++;

        if(this->month > 12){
            this->year++;
            this->month -= 12;
        }
    }

    return *this;
}

Date& Date :: operator-=(int x){
    this->day -= x;

    while(this->day <= 0){
        this->month--;

        if(this->month < 1){
            this->year--;
            this->month = 12;
        }

        this->day += day_in_month(this->month, this->year);
    }

    return *this;
}

//Typecasting
Date :: operator int(){
    int sum = 0;
    for(int i = 1; i < this->month; i++){
        sum += day_in_month(this->month, this->year);
    }
    sum += this->day;
    return sum;
}

Date :: operator long(){
    long sum = 0;

    for(int i = 1; i < this->year; i++){
        if(isLeap(i)) sum += 366;
        else sum += 365;
    }

    for(int j = 1; j < this->month; j++){
        sum += day_in_month(j, this->year);
    }

    sum += this->day;
    return sum;
}

//Tomorrow and Yesterday method
Date Date :: Tomorrow(){
    Date res = *this;

    res.day += 1;

    while(res.day > day_in_month(res.month, res.year)){
        res.day -= day_in_month(res.month, res.year);

        res.month++;

        if(res.month > 12){
            res.year++;
            res.month = 1;
        }
    }

    return res;
}

Date Date :: Yesterday(){
    Date res = *this;

    res.day -= 1;

    while(res.day <= 0){
        res.month--;

        if(res.month < 1){
            res.year--;
            res.month = 12;
        }

        res.day += day_in_month(res.month, res.year);
    }

    return res;
}