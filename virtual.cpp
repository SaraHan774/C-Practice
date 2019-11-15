#include <iostream>
#include <string>
using namespace std;

class Figure{
public:
    virtual string draw() = 0;

};

class Triangle : public Figure{
public:
    virtual string draw(){
        return "Draw Triangle";
    }
};

class Square : public Figure{
public:
    virtual string draw(){
        return "Draw Square";
    }
};

class Circle : public Figure{
public:
    virtual string draw(){
        return "Draw Circle";
    }
};

int main() {
    Figure* figure = new Triangle;
    Figure* figure1 = new Square;
    Figure* figure2 = new Circle;

    cout << figure -> draw() << endl;
    cout << figure1 -> draw() << endl;
    cout << figure2 -> draw() << endl;

    delete figure;
    delete figure1;
    delete figure2;

    return 0;
}