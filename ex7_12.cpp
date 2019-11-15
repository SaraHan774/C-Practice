//
// Created by sarah on 11/15/2019.
//

#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;

public:
    Power(int kick = 0, int punch = 0){
        this -> kick = kick;
        this -> punch = punch;
    }

    void show();
    friend Power operator+(Power op1, Power op2);
    friend bool operator>(Power op1, int x);
    friend int operator&(Power op1, Power op2);
};

void Power::show() {
    cout << "k : " << kick << " p : " << punch << endl;
}

Power operator+(Power op1, Power op2){
    Power tmp;
    tmp.kick = op1.kick + op2.kick;
    tmp.punch = op1.punch + op2.punch;
    return tmp;
}

bool operator>(const Power op1, const int x){
    return (op1.kick > x) && (op1.punch) > x;
}

//TODO : How to overload bit AND operator ?
int operator&(const Power op1, const Power op2){
    return op1.kick & op2.kick & op2.punch & op2.kick;
}

int main(){
    Power power(10, 20), power1(20, 1000);
    Power addPower = power + power1;

    power.show(); //k : 10 p : 20
    power1.show(); //k : 20 p : 1000
    addPower.show(); //k : 30 p : 1020
    return 0;
}