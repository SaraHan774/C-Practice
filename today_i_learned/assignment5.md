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

* b) Change the throw statement in line 5 so that it throws objects of your exception class.

* c) Add a catch block in main for catching exception-objects of your exception class.

* d) Change your code so that it works with objects created on the heap by using the new operator. Discuss the positive and negative aspects of such an object-reference based approach for exception handling.
