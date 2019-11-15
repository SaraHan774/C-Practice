//
// Created by sarah on 11/15/2019.
//
#include <iostream>
using namespace std;
#define ARR_MAX_SIZE 50

class Stack{
    int * arr;
    int top;
public:
    Stack(){
        arr = new int[ARR_MAX_SIZE];
        this -> top = -1;
    }
    int operator>>(int& op);
    Stack& operator<<(int op);
    bool operator!();
    int * getArr(){ return arr; }
    int getTop(){ return top; }
};

Stack& Stack::operator<<(int op) {
    if(top >= ARR_MAX_SIZE - 1){
        perror("Stack Overflow");
        exit(EXIT_FAILURE);
    }
    (this -> getArr())[++top] = op;
    return *this;
}

int Stack::operator>>(int& op) {
    if(getTop() != -1){
        op = (this -> getArr())[top--];
        return op;
    }
    return -1;
}

bool Stack::operator!() {
    if(getTop() == -1){ return true;}
    else{ return false;}
}

int main(){
    Stack stack = Stack();
    stack << 3 << 5 << 10 ; //차례대로 push 한다

    cout << "top index : " << stack.getTop() << endl;

    while(true){
        if(!stack){ //if the stack is empty
            break;
        }
        int x;
        stack >> x; //pop x
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}