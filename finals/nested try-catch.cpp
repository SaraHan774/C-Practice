#include <iostream>

void foo() {
	try {
		try {
			throw (double)1;
		}
		catch (int i) {
			std::cout << "inner catch. i = " << i;
		}
	}
	catch (double d) {
		std::cout << "outer catch. d = " << d;
	}
}


void main() {
	foo();
}