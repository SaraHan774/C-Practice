//
// Created by sarah on 12/9/2019.
//

#include <iostream>
using namespace std;


class Circle{
public:
    double radius;
    Circle(){
        this -> radius = 0;
    }
    Circle(double radius){
        this -> radius = radius;
    }
    Circle add(Circle & c){
        return Circle(this -> radius + c.radius);
    }

    //operator overloading
    Circle operator+(Circle & c){
        return Circle(c.radius + this -> radius);
    }

    Circle operator+(double d){
        return Circle(this -> radius + d);
    }


};



int main(){
    Circle circle(5);
    Circle circle1(10);

    cout << "Circle + " <<  << endl;
    return 0;
}
