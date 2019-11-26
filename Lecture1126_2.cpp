//
// Created by sarah on 11/26/2019.
//

#include <iostream>
#include <cstring>

using namespace std;

//integral parameter
template<typename TYPE1, int C>


class List{
public:
    TYPE1 key1;
    //List<TYPE1, C-1> subList; // compile time arithmetic

    void print(){
        cout << C << endl;
    }

};

template<typename TYPE>
//code redundancy ! (same kind of problem with classes)
//generic, type-safe (!),
TYPE add(TYPE x, TYPE y){
       return x + y;
}

//double add(double x, double y){
//    return x + y;
//}

//template specialization
//special implementation for a specific type

char * add(char * x, char * y){
    return strcat(x, y);
}
//
//int main(){
//
//    //meta language
//
////    List<List<int>*> nestedList;
//
//    List<int, 10> list;
//    list.print();
////    list.subList.print();
//
//
//    //add 함수의 문제점은 ?
////    char *s1 = "Today";
////    char *s2 = "is a nice day...";
////    cout << add(s1, s2) << endl; //addition of two pointers has no meaning
//
//    char string1[100] = "Today";
//    char string2[100] = " is a nice day";
//    cout << add(string1, string2) << endl;
//
//    int x = 5; double y = 8;
//    cout << add<double>(x, y) << endl; //type inference
//    //x를 자동으로 double 로 만들도록 함.
//
//    return 0;
//}