#include "Triangle.h"
#include "Point.h"

Triangle :: Triangle(){}

void Triangle :: compute_edge(){
    edge1 = A.dist_a_b(B);
    edge2 = A.dist_a_b(C);
    edge3 = B.dist_a_b(C);
}

Triangle :: Triangle(Point A, Point B, Point C){
    this->A = A;
    this->B = B;
    this->C = C;
    compute_edge();
}

bool Triangle :: is_Valid_Triangle(){
    if((edge1 + edge2) > edge3 && (edge1 + edge3) > edge2 && (edge2 + edge3) > edge1) return true;
    return false;
}

string Triangle :: type_of_triangle(){
    string ans = "";

    if(is_Valid_Triangle()){
        if(pow(edge1, 2) + pow(edge2, 2) == pow(edge3, 2) ||
            pow(edge1, 2) + pow(edge3, 2) == pow(edge2, 2) ||
            pow(edge2, 2) + pow(edge3, 2) == pow(edge1, 2) ){
                if(edge1 == edge2 || edge1 == edge3 || edge2 == edge3) ans = "Right Isosceles Triangle";
                else ans = "Right Triangle";
        }  
        else if(edge1 == edge2 && edge1 == edge3) ans = "Equilateral Triangle";
        else if(edge1 == edge2 || edge1 == edge3 || edge2 == edge3) ans = "Isosceles Triangle";
        else ans = "Scalene Triangle"; 
    }
    if(ans != "") return ans;
    return ans = "Not Triangle";
}


float Triangle :: perimeter(){
    return edge1 + edge2 + edge3;
}

float Triangle :: area(){
    float ans = 0;

    if(is_Valid_Triangle()){
        float p = perimeter() / 2.0;
        ans = sqrt(p * (p - edge1) * (p - edge2) * (p - edge3));
    }

    return ans;
}

Point Triangle :: center(){
    float gx = (A.get_x() + B.get_x() + C.get_x()) / 3.0;
    float gy = (A.get_y() + B.get_y() + C.get_y()) / 3.0;
    
    Point G(gx, gy);
    return G;
}

void Triangle :: input(){
    A.input();
    B.input();
    C.input();
}

void Triangle :: output(){
    cout << "A: "; A.output(); cout << endl;
    cout << "B: "; B.output(); cout << endl;
    cout << "C: "; C.output(); cout << endl;
}