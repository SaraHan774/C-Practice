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
    friend Power& operator++(Power& op); //전위 연산자 ++ 프렌드 선언
    friend Power operator++(Power& op, int x); //후위 연산자 ++ 프렌드 선언, x 는 전위연산자와 구분하기 위한 의미없는 숫자.
};

void Power::show() {
    cout << "kick : " << kick << " punch : " << punch << endl;
}

Power& operator++(Power& op) {
    op.kick++;
    op.punch++;
    return op; //연산 결과 리턴
}

Power operator++(Power& op, int x) {
    Power tmp = op;
    op.kick++;
    op.punch++;
    return tmp; //변경 이전의 op 리턴
}

int main(){
    Power a(3, 5), b;
    b = ++a; //전위 연산자
    a.show();
    b.show();

    b = a++; //후위 연산자
    a.show(); //a의 값들은 바뀌었지만
    b.show(); //++이 리턴하는 것은 바뀌기 전의 a이다.

//    kick : 4 punch : 6
//    kick : 4 punch : 6
//    kick : 5 punch : 7
//    kick : 4 punch : 6
}