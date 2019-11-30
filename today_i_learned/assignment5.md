## Handout 5
### Introduction to Programming in C++
* Due : 2019/12/03
* **2016035478 Gahee Han (한가희)** 

#### Exercise 1: Given the following C++ code:

```
#include <iostream>
void fun() {
	try {
		std::cout << "FA\n";
		throw 3; // line 5
		std::cout << "BA\n";
	}
	catch (int i) {
		std::cout << "FCA " << i << "\n";
	}
	catch (char c) {
		std::cout << "FCB " << c << "\n";
		throw;
	}
	std::cout << "BC\n";
}

void main() {
	try {
		std::cout << "A\n"; 
		fun();
		std::cout << "B\n"; 
	}
	catch (int i) { 
		std::cout << "C " << i << "\n"; 
	}
	catch (double d) { 
		std::cout << "D " << d << "\n"; 
	}
	catch (...) { 
		std::cout << "E\n";
	}
	std::cout << "F\n";
}
```
 
#### 1-a. What is the output of the above code?

```
A
FA
FCA 3
BC
B
F
```

#### 1-b) What is the output of the above code, if the throw-statement in line 5 is replaced by:

* i) throw (double)5.0;

    ```
    A
    FA
    D 5
    F
    ```
  
* ii) throw 'c';

    ```
    A
    FA
    FCB c
    E
    F
    ```

* iii) throw true;

    ```
    A
    FA
    E
    F
    ```

* First try to develop the answers by simply analysing the code. Afterwards take a compiler for verifying whether your answers were right or not.	


#### Exercise 2

* a) Extend the above code by adding an exception class for exception-object creation. Your exception class should comprise an error indicating attribute (e.g. by using an integer.) and an appropriate constructor.
    * Created `MyException` class which is extended by `InvalidAttributeException` class. 
* b) Change the throw statement in line 5 so that it throws objects of your exception class.
    * changed line 5 to throw `InvalidAttributeException` 
* c) Add a catch block in main for catching exception-objects of your exception class.
    * added `catch` block in `main()` for catching `InvalidAttributeException`.
* d) Change your code so that it works with objects created on the heap by using the new operator. Discuss the positive and negative aspects of such an object-reference based approach for exception handling.
    * Created `MyObject` class & initialized with `new` keyword. 
    * This approach might cause "Zombie object" problem due to the fact that `delete` keyword is unreachable after a `throw` statement.   
    * However this method is useful for dynamically creating an object and removing them from memory after done using it, if `delete` is guaranteed.
      
```
//
// Created by sarah on 11/30/2019.
//

#include <iostream>
#include <string>
using namespace std;

// ***** added my own exception class *****
class MyException{
    int lineNo;
    string func, msg;

public:
    MyException(int lineNo, string func, string msg){
        this->lineNo = lineNo;
        this->func = func;
        this->msg = msg;
    }

    void print(){
        cout << func << " : " << lineNo
        << " , " << msg << endl;
    }
};


// ***** added my own exception class *****
class InvalidAttributeException : public MyException{
public:
    InvalidAttributeException(int lineNo, string func, string msg)
    : MyException(lineNo, func, msg){}

};


// ***** added my own class *****
class MyObject{
public:
    MyObject(){
        cout << "MyObject Constructor Running ... " << endl;
    }

    ~MyObject(){
        cout << "MyObject Destructor Running ... " << endl;
    }
};


void fun() {
    try {
        std::cout << "FA\n";
        throw InvalidAttributeException(5, "fun()", "Invalid Attribute !"); // line 5
        std::cout << "BA\n";
    }
    catch (int i) {
        std::cout << "FCA " << i << "\n";
    }
    catch (char c) {
        std::cout << "FCB " << c << "\n";
        throw;
    }
    std::cout << "BC\n";
}


int main() {

    //Creating MyObject
    try{
        MyObject * object = new MyObject();
        throw 50; 
        
        //Unreachable code 'delete ~ ' 
        delete object; 
    }catch (int myException){
        cout << "Catch : " << myException << endl; 
    }


    try {
        std::cout << "A\n";
        fun();
        std::cout << "B\n";
    }
    catch (int i) {
        std::cout << "C " << i << "\n";
    }
    catch (double d) {
        std::cout << "D " << d << "\n";
    }
// ***** added my own exception class ***** 
    catch (InvalidAttributeException &e){
        e.print();
    }
    catch (...) {
        std::cout << "E\n";
    }

    std::cout << "F\n";

    return 0;
}

```