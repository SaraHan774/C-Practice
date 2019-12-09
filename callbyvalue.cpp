//
// Created by sarah on 12/3/2019.
//

#include <iostream>
using namespace std;

class Circle2{
private:
    int radius;
public:
    //복사 생성자를 따로 만들지 않아도 컴파일러는 default copy constructor 를
    //묵시적으로 삽입하고, 그 생성자를 호출하도록 컴파일한다.
    Circle2(const Circle2& c){
        //복사 생성자 선언
        this -> radius = c.radius;
        cout << "Copy Constructor running ! radius = " << radius << endl;
    }

    Circle2(){
        radius = 1;
    }

    Circle2(int radius){
        this -> radius = radius;
    }

    double getArea(){
        return 3.14 * radius * radius;
    }

};

class Circle{
private:
    int radius;

public:
    Circle();
    Circle(int r);
    ~Circle();

    double getArea(){
        return 3.14 * radius * radius;
    }
    int getRadius(){
        return radius;
    }
    void setRadius(int r){
        this -> radius = r;
    }
};

Circle::Circle(){
    radius = 1;
    cout << "Constructor running ! Radius = " << radius << endl;
}

Circle::Circle(int radius){
    this -> radius = radius;
    cout << "Constructor running ! Radius = " << radius << endl;
}

Circle::~Circle(){
    cout << "Destructor running ! Radius = " << radius << endl;
}

void increase(Circle c){
    //waffle 의 내용이 그대로 c에 복사된다.
    //객체 c 의 생성자가 실행되지 않는다.
    int r = c.getRadius();
    c.setRadius(r + 1);
    //객체 c의 소멸자가 실행된다.
}

int main(){
    Circle waffle(30);
    increase(waffle);
    cout <<"Radius of waffle = " << waffle.getRadius() << endl;
    //waffle 의 소멸자가 실행된다.


    //Circle2 Test
    Circle2 src(300);
    Circle2 dest(src); //dest 객체의 복사 생성자 호출

    cout << "Original Area : " << src.getArea() << endl;
    cout << "Copy Area : " << dest.getArea() << endl;
}

//output :
//Constructor running ! Radius = 30
//Destructor running ! Radius = 31
//Radius of waffle = 30
//Destructor running ! Radius = 30