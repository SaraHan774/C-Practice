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

    int getRef(){
        return objARef -> x;
    }

};

class B : public A{
public:
    A objA;

    int getX(){
        return x;
    }

    int getZ(){
        //objA.z 는 안됨 !
        return z;
    }

    int getRefB(){
        return objARef -> x;
    }
};

class C{
public:
    A objA;
    A *objARef;
    B objB;

//    int getX(){
//        return x;
//    }

    int getRefC(){
        return objARef -> x;
    }

    int getObjBX(){
        return objB.x;
    }

    int getProtected(){
        return objB.z;
    }
};

int main(){

    A testA = A();
    B testB = B();
    C testC = C();



    return 0;
}

