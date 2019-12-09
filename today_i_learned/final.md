## 기말고사 대비 

### 클래스 
* 초기화 
    * `Circle c`; 
    * `Circle waffle(30)` 
    
* getter & setter 
    * private 변수에 대한 접근, 변경 
    
* Overriding 
```
//Circle 클래스의 area 메소드를 오버라이딩 한다. 
double Cylinder::area(){
    //protected 접근 상속 객체를 통해서 가능, 원 객체를 통해서는 불가능. 
    return 2*Circle::area() + 2*3.14*protected_r;
}
```

* Destructor 
```
class Circle{ ... };
class Cylinder : public Circle{ ... }; 

int main(){
    Circle c; //Desctructor call 1
    Cylinder cyliner(10, 5); // Destructor call 2 
    return 0; 
} 

```
=> Destructor 가 두 번 불린다. 상속된 객체에 의해서 한 번 더 불림. 

* Dynamic Binding 
```
Cylinder* cy = new Cylinder(10, 5); 
Circle* cir = new Circle(9); 

Circle* cir1 = cy; //다형성으로 인해서 Circle 타입이 될 수 있다. 

cout << cir1 -> area(); 
//동적 바인딩으로 인해서, Cylinder 의 area()구현을 사용할 수 있다.  
```

* 상속을 한 경우 superclass 의 생성자도 함께 불린다. 

### Templates 

* Factorial 를 템플릿으로 구현하기 
```
#include <iostream>

using namespace std;

template <long N> 
class Factorial { 
public: 
	long Value(void) { 
		return N * fn_1.Value(); 
	} 
private: 
	Factorial<N-1> fn_1; 
};

template <> 
class Factorial<0> { 
public: 
	long Value(void) { return 1; } 
}; 

void main() {
	Factorial<15> f; 
	cout << f.Value() << endl;
}
```

* Char 비교 함수는 별도로 만들어 주어야.
    * `#include <cstring>`  => `strcmp()` 
```
//템플릿
template <class TP>
TP max_value(TP d1, TP d2){
    return (d1 > d2) ? d1 : d2;
}

template <>
char * max_value(char* d1, char* d2){
    return (strcmp(d1, d2) > 0) ? d1 : d2;
}
```


### Exception 
* Exception 클래스 
```
//Exception
class Exception{
public:
    int code;
    Exception(int i){
        code = i;
    }
    void printMsg(){
        cout << "Error Code : " << code << endl;
    }
    ~Exception(){
        cout << "deleting exception object" << endl;
    }
};
```

* Exception object created with `new`
```
void foo(){
    try{
        throw new Exception(5000);
    }
    catch(Exception* e){
        e -> printMsg();
        delete e; //delete 가 이루어진다. 
    }
}
```

* Exception `call by value`
```
void foo(){
    try{
        throw Exception(5000);
    }
    catch(Exception e){
        e.printMsg();
    }
}
```

* 다시 던지기 
    * catch 블럭에서 다시 throw 를 하면 해당 catch 블럭에서 잡은 값이 다시 throw 됨. 

* stack unwinding and exceptions 
    * 스택 되감기 
    * throw 밑의 구문은 실행이 되지 않는다. 
    * main -> f1 -> f2 -> f3 throw Exception 인 경우 
    * 다시 f3 -> f2 -> f1 으로 돌아와서 main 에서 catch 가 이루어진다.
        * catch 를 만날때까지 계속 스택을 정리하면서 자신의 호출원을 찾아간다. 
        * 이것을 스택 되감기 (stack unwinding) 이라고 함.  

* The process of removing function entries from function call stack at run time is called Stack Unwinding.



* 결과 : 
```
Error Code : 5000
deleting exception object
deleting exception object
// 객체가 매개변수에 복사되어서 들어가기 때문에 destructor 가 두 번 호출됨.  
```

