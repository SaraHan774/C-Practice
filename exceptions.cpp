//
// Created by sarah on 11/19/2019.
//

#include <iostream>
using namespace std;

class Exception{
public:
    int info;
    Exception(int info){
        cout << "construct" << endl;
        this -> info = info;
    }

    ~Exception(){
        cout << "destruct" << endl;
    }
};

class SubException : public Exception{

public:
    SubException(int info) : Exception(5) {
        cout << "sub construct" << endl;
        this -> info = info;
    }

    ~SubException(){
        cout << "sub destruct" << endl;
    }
};

class A{
public:
    A(){
     cout << "Constructed A object" << endl;
    }
    ~A(){
        cout << "Destructed A object" << endl;
    }
};

void fun(){

    cout << "before throw in fun" << endl;
    throw SubException(3);
    cout << "after throw in fun"<<endl;
}

int main(){

    try{
        cout << "before call fun()" << endl;
        fun();
        cout << "after call fun()" << endl;
    }
    catch (const SubException exception){ //Call by value => make copies ! => pass by reference 로 바꾸자.
        cout << "exception with " << exception.info << endl;
        cout <<"after catch" << endl;
        //destruction 1 => copy of the Exception object
        //destruction 2 => copy 랑 같이 제거됨... catch 블럭 내부에서 그냥 살아있다가.
    }
}
