//
// Created by sarah on 12/3/2019.
//

#include <iostream>
#include <cstring>

using namespace std;

//making Circle class
class Circle{
protected:
    //Cylinder 구현에서 사용될 반지름 변수
    double protected_r;

private:
    double private_r;

public:
    double radius;
    double area();
    void setRadius(double r);
    const Circle operator+(const Circle &other) const;
    friend ostream & operator<<(ostream & os, const Circle c);
    Circle();
    Circle(double r);
    ~Circle();
};

const Circle Circle::operator+(const class Circle & other) const{
    Circle c = *this;
    c.radius += other.radius;
    return c;
}

std::ostream & operator<<(std::ostream & os, const Circle c){
    os << "radius : " << c.radius;
    return os;
}

Circle::Circle(){
    radius = 1;
}

Circle::Circle(double r) {
    radius = r;
}

double Circle::area() {
    return radius * radius * 3.14;
}

void Circle::setRadius(double r){
    private_r = r;
}

Circle::~Circle(){
    cout << "Goodbye, object ! " << endl;
}

//making class Cylinder extending Circle
class Cylinder : public Circle{
private:
    //원에는 없는 속성을 정의
    double height;
public:
    double volume();
    double area();
    Cylinder(double r1, double r, double h);

};

//Cylinder 안의 메소드들을 구현한다.
double Cylinder::volume() {
    return area() * height;
}

double Cylinder::area(){
    //protected 접근 상속 객체를 통해서 가능, 원 객체를 통해서는 불가능.
    return 2*Circle::area() + 2*3.14*protected_r;
}

Cylinder::Cylinder(double r1, double r, double h) : Circle(r1) {
    protected_r = r;
    height = h;
}


//Exception
class Exception{
public:
    int code;
    Exception(int i){
        code = i;
    }
    void printMsg(){
        cout << "Error Code : " << code << endl;
    }
    ~Exception(){
        cout << "deleting exception object" << endl;
    }
};

void foo(){
    try{
        throw Exception(5000);
    }
    catch(Exception e){
        e.printMsg();
    }
}

//다시 throw 하기
void reFoo(){
    try{
        throw (double) 1;
    }catch (double d){
        cout << "catch 1 d : " << d << endl;
        throw;
    }
}

void reFoo2() {
    try {
        try {
            throw (double)1;
        }
        catch (double d) {
            std::cout << "inner catch. d = " << d;
            throw; // We rethrow the exception d
        }
    }
    catch (double d) {
        std::cout << "outer catch. d = " << d;
    }
}


//템플릿
template <class TP>
TP max_value(TP d1, TP d2){
    return (d1 > d2) ? d1 : d2;
}

template <>
char * max_value(char* d1, char* d2){
    return (strcmp(d1, d2) > 0) ? d1 : d2;
}

int main(){
//    cout << max_value(4, 12) << endl;
//    cout << max_value(5.0, 6.0) << endl;
//    cout << max_value('A', 'C') << endl;
//    cout << max_value("cat", "mouse")<< endl;

    reFoo2();

//    foo();


//    Circle c;
//    c.radius = 5.0;
//    cout << c.area() << endl;
//
//    c.setRadius(30.0);
//    cout << "Area changed : " << c.area() << endl;
//
//    Cylinder cylinder(0, 10, 5);
//    cout << "Area of the Cylinder : "<< cylinder.area() << endl;
//
//    Circle c1 = Circle(5.0);
//    Circle c2 = Circle(6.0);
//
//    cout << (c1 + c2).radius << endl;
//    cout << c1 << endl;

    return  0;
}