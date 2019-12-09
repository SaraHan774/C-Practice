#include <iostream>

void foo() {
	try {
		throw (double)1;
	}
	catch (double d) {
		std::cout << "catch 1 d = " << d;
		throw; 
	}
}

void main() {
	try {
		foo();
	}
	catch (double d) {
		std::cout << "catch 2 d = " << d;
	}
}

//둘 다 1이 출력됨.