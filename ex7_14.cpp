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
    Power& operator<<(int n); //연산 후 Power 객체의 참조를 리턴
};

void Power::show() {
    cout << "kick : " << kick << "punch : " << punch << endl;
}

Power& Power::operator<<(int n) {
    kick += n;
    punch += n;
    return *this; //이 객체의 참조를 리턴한다
}

int main(){
    Power a(1, 2);
    a << 3 << 5 << 6; // a 객체의 각각의 속성에 3, 5, 6 의 순서로 더해진다.
    a.show();
    return 0;
}

