#include "header.h"
using namespace std;

//Default Constructor
student :: student() : id(0), fullname(nullptr), address(nullptr), gpa(0.0){
    cout << "student::Default cons" << endl;
}

//Parameters Contructor
student :: student(int id, const char* fullname, const char* address, double gpa){
    this->id = id;
    this->gpa = gpa;

    int size_1 = strlen(fullname);
    this->fullname = new char[size_1+1];

    for(int i = 0; i < size_1; i++){
        this->fullname[i] = fullname[i];
    }
    this->fullname[size_1] = '\0';

    int size_2 = strlen(address);
    this->address = new char[size_2+1];

    for(int i = 0; i < size_2; i++){
        this->address[i] = address[i];
    }
    this->address[size_2] = '\0';

    cout << "student::Parameters cons" << endl;
}

//Copy Constructor
student :: student(const student& other){
    this->id = other.id;
    this->gpa = other.gpa;

    int size_1 = strlen(other.fullname);
    this->fullname = new char[size_1+1];

    for(int i = 0; i < size_1; i++){
        this->fullname[i] = other.fullname[i];
    }
    this->fullname[size_1] = '\0';

    int size_2 = strlen(other.address);
    this->address = new char[size_2+1];

    for(int i = 0; i < size_2; i++){
        this->address[i] = other.address[i];
    }
    this->address[size_2] = '\0';

    cout << "student::Copy cons" << endl;
}

//Assignment Operator
student& student :: operator=(const student& other){
    if(this != &other){
        delete [] fullname;
        delete [] address;

        this->id = other.id;
        this->gpa = other.gpa;

        int size_1 = strlen(other.fullname);
        this->fullname = new char[size_1+1];

        for(int i = 0; i < size_1; i++){
            this->fullname[i] = other.fullname[i];
        }
        this->fullname[size_1] = '\0';

        int size_2 = strlen(other.address);
        this->address = new char[size_2+1];

        for(int i = 0; i < size_2; i++){
            this->address[i] = other.address[i];
        }
        this->address[size_2] = '\0';
    }
    
    cout << "student::Assignment Operator" << endl;
    return *this;
}

//String Constructor: id-fullname-address-gpa
student :: student(string str){
    string tmp = "";
    vector<string> v;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '-'){
            if(!tmp.empty()){
                v.push_back(tmp);
                tmp = "";
            }
        }
        else{
            tmp += str[i];
        }
    }

    v.push_back(tmp);

    this->id = stoi(v[0]);
    this->gpa = stod(v[3]);

    string str_1 = v[1];
    int size_1 = str_1.size();
    this->fullname = new char[size_1+1];

    for(int i = 0; i < size_1; i++){
        this->fullname[i] = str_1[i];
    }
    this->fullname[size_1] = '\0';

    string str_2 = v[2];
    int size_2 = str_2.size();
    this->address = new char[size_2+1];

    for(int i = 0; i < size_2; i++){
        this->address[i] = str_2[i];
    }
    this->address[size_2] = '\0';
    cout << "student::String cons" << endl;
}



//Getter and Setter
void student :: set_id(int id){
    this->id = id;
}
int student :: get_id(){
    return id;
}

void student :: set_gpa(double gpa){
    this->gpa = gpa;
}
double student :: get_gpa(){
    return gpa;
}

void student :: set_fullname(const char* fullname){
    delete [] this->fullname;

    int size = strlen(fullname);
    this->fullname = new char[size+1];

    for(int i = 0; i < size; i++){
        this->fullname[i] = fullname[i];
    }
    this->fullname[size] = '\0';
}
char* student :: get_fullname(){
    return fullname;
}

void student :: set_address(const char* address){
    delete [] this->address;

    int size = strlen(address);
    this->address = new char[size+1];

    for(int i = 0; i < size; i++){
        this->address[i] = address[i];
    }
    this->address[size] = '\0';
}
char* student :: get_address(){
    return address;
}

//to_string method
string student :: to_String(){
    string res = "";
    string fullname_tmp = "";
    string address_tmp = "";

    if(fullname != nullptr){
        fullname_tmp = fullname;
    }
    else fullname_tmp = "Unknown";

    if(address != nullptr){
        address_tmp = address;
    }
    else address_tmp = "Unknown";

    res = to_string(id) + " - " + fullname_tmp + " - " + address_tmp + " - " + to_string(gpa);   
    return res; 
}

//clone method
student student :: clone(){
    return student(*this);
}

//output method
void student :: output(){
    cout << "Id: " << id << endl;
    if(fullname != nullptr){
        cout << "Full Name: " << fullname << endl;
    }
    else cout << "Full Name: Unknown" << endl;

    if(address != nullptr){
        cout << "Address: " << address << endl;
    }
    else cout << "Fulle Name: Unknown" << endl;
    cout << "GPA: " << fixed << setprecision(4) << gpa << endl;
}

//Destructor
student :: ~student(){
    id = 0;
    gpa = 0.0;
    delete [] fullname;
    delete [] address;
}