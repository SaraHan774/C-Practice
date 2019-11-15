//
// Created by sarah on 11/15/2019.
//

#include <iostream>
using namespace std;
#define LOG(X) cout << X << endl

class A{
public:
    int x;
    A *objARef;
private:
    int y;
protected:
    int z;

};

class B : public A{
public:
    A objA;
};

class C{
public:
    A objA;
    A *objARef;
    B ojbB;
};

int main(){

    A testA = A();
    B testB = B();
    C testC = C();



    return 0;
}

