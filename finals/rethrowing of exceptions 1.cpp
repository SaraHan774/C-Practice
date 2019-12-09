#include <iostream>

void foo() {
	try {
		try {
			throw (double)1;
		}
		catch (double d) {
			std::cout << "inner catch. d = " << d;
			throw; // We rethrow the exception d
		}
	}
	catch (double d) {
		std::cout << "outer catch. d = " << d;
	}
}

//둘 다 1 이 출력됨.


void main() {
	foo();
}