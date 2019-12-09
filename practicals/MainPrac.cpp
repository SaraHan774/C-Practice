//
// Created by sarah on 12/9/2019.
//

#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
public:
    Person(){name = "";}
    Person(string name){this -> name = name;}
    string getName(){return name;}
    void setName(string name){
        this -> name = name;
    }
};

class Family{
    Person * p;
    string famName;
    int size; //person 배열의 크기
public:
    Family(string name, int size){
        this -> famName = name;
        this -> size = size;
        p = new Person[this -> size];
    }
    void setName(int index, string name){
        p[index].setName(name);
    };
    void show(){
        cout << famName << " Family has " << size << " Members." << endl;

        for(int i = 0; i < size; i++){
            cout << p[i].getName() << "\t";
        }
        cout << endl;
    }
    ~Family(){
        delete [] p;
    }
};

class A{
private:
    int x;
protected:
    int y;
public:
    int z;
};
class B : public A{

public:
    A objA;

//    int getX(){
//        return x; ERROR ! - private
//    }
    int getY(){
        return y; //OK - Protected ~ Subclass
    }
//    int getYFromA(){
//        return objA.y; ERROR ! - Protected !
//    }

    int getZ(){
        return z;
    }
};

class C{
public:
    B objB;
    int getYFromB(){
        //int y = objB.y; ERROR !
        int y = objB.getY(); //OK
        return y;
    }
    int getZ(){ //BOTH ARE OK
        int zFromA = objB.z;
        int zFromB = objB.getZ();
        return zFromA;
    }
    int getZViaObjA(){
        return objB.objA.z;
    }
};

int main(){

    Family * simpson = new Family("Simpson", 3);
    simpson -> setName(0, "Mr. Simpson");
    simpson -> setName(1, "Mrs. Simpson");
    simpson -> setName(2, "Bart Simpson");

    simpson -> show();

    delete simpson;
    return 0;
}