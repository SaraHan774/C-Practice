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
    friend Power operator+(int op1, Power op2);
};

void Power::show() {
    cout << "kick : " << kick << " punch : " << punch << endl;
}

//연산자 함수를 외부 함수로 구현한다.
Power operator+(int op1, Power op2){
    Power tmp; //임시 객체 만들기
    tmp.kick = op1 + op2.kick;
    tmp.punch = op1 + op2.punch; //각각의 속성에 int 값을 더해서 tmp변수에 할당
    return tmp;
}

int main(){
    Power a(3, 5), b;
    a.show();
    b.show();

    b = 2 + a; //위에서 오버로딩한 연산자 함수 호출
    a.show(); //a 객체 자체를 바꾸지 않는다.
    b.show();

//kick : 3 punch : 5
//kick : 0 punch : 0
//2를 각각 더해준 결과를 b에 저장한다. a 객체를 바꾸지는 않는다.
//kick : 3 punch : 5
//kick : 5 punch : 7
}