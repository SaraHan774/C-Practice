//
// Created by sarah on 12/9/2019.
//


#include <iostream>
using  namespace std;

class Circle{
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r){
        radius = r;
    }
    double getArea(){
        return 3.14 * radius * radius;
    }
};

Circle::Circle(){
    radius = 1;
    cout << "Constructor running ...  radius = " << radius << endl;
}

Circle::Circle(int r){
    radius = r;
    cout << "Constructor running ...  radius = " << radius << endl;
}

Circle::~Circle(){
    cout << "Destructor running ...  radius = " << radius << endl;
}

int main(){
    int radius;
    while(true){
        cout << "Enter Circle Radius (Exit if negative num) >> ";
        cin >> radius;

        if(radius < 0){
            break;
        }
        Circle * p = new Circle(radius);
        cout << "Circle Area = " << p -> getArea() << endl;
        delete p; //객체 반환
    }
}
