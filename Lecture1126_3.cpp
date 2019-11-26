//
// Created by sarah on 11/26/2019.
//

#include <iostream>
using namespace std;

template<int C>

class A{

public:
    int getTemplateArg(){
        return C;
    }
};

template<>
class A<0>{
public:
    int getTemplateArg(){
        return 20;
    }
};



int main(){
    A<0> obj;
    cout << obj.getTemplateArg() << endl;

    return 0;
}