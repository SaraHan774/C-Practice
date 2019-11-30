//
// Created by sarah on 11/30/2019.
//

#include <iostream>
#include <string>
using namespace std;

class MyException{
    int lineNo;
    string func, msg;

public:
    MyException(int lineNo, string func, string msg){
        this->lineNo = lineNo;
        this->func = func;
        this->msg = msg;
    }

    void print(){
        cout << func << " : " << lineNo
        << " , " << msg << endl;
    }
};

class InvalidAttributeException : public MyException{
public:
    InvalidAttributeException(int lineNo, string func, string msg)
    : MyException(lineNo, func, msg){}

};

class MyObject{
public:
    MyObject(){
        cout << "MyObject Constructor Running ... " << endl;
    }

    ~MyObject(){
        cout << "MyObject Destructor Running ... " << endl;
    }
};

void fun() {
    try {
        std::cout << "FA\n";
        throw InvalidAttributeException(5, "fun()", "Invalid Attribute !"); // line 5
        std::cout << "BA\n";
    }
    catch (int i) {
        std::cout << "FCA " << i << "\n";
    }
    catch (char c) {
        std::cout << "FCB " << c << "\n";
        throw;
    }
    std::cout << "BC\n";
}

int main() {

    //Creating MyObject
    try{
        MyObject * object = new MyObject();
        throw 50;

        //Unreachable code 'delete ~ '
        delete object;
    }catch (int myException){
        cout << "Catch : " << myException << endl;
    }


    try {
        std::cout << "A\n";
        fun();
        std::cout << "B\n";
    }
    catch (int i) {
        std::cout << "C " << i << "\n";
    }
    catch (double d) {
        std::cout << "D " << d << "\n";
    }
    catch (InvalidAttributeException &e){
        e.print();
    }
    catch (...) {
        std::cout << "E\n";
    }

    std::cout << "F\n";

    return 0;
}
