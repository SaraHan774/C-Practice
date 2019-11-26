//
// Created by sarah on 11/26/2019.
//

#include <iostream>
using namespace std;
template<typename TYPE1, typename TYPE2>

class List{
public:
    TYPE1 key1;
    TYPE2 key2;
    List<TYPE1, TYPE2> * next;

    List<TYPE1, TYPE2> * append(TYPE1 key1, TYPE2 key2){ // double 이 담기는 List 를 원할 때는 ? 각 타입별로 만들어 줘야 ...
        List<TYPE1, TYPE2> * fresh = new List<TYPE1, TYPE2>;
        fresh -> key1 = key1;
        fresh -> key2 = key2;
        fresh ->  next = NULL;
        this -> next = fresh;
        return fresh;
    }
};

//좀 더 제네릭한 방법이 필요하다. Flexible 한 ...
//compile time 에 type safe 한 것을 원한다.
//Type itself is a variable

//int main(){
////    List<int> myList = List<int>();
////    List<double> myDoubleList = List<double>();
////    //이런 것도 가능하구나 ...
////    myList.append(12) -> append(4);
////    myDoubleList.append(13.4) -> append(234.88);
//
//    List<int, char *> twoParamList = List<int, char *>();
//    twoParamList.append(12, "Name1") -> append(32, "Name2");
//
//    return 0;
//}