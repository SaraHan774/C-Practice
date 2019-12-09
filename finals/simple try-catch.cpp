#include <iostream>

void foo() {
	try {
		if (1) {
			throw 1;
		}
	}
	catch (int i) {
		std::cout << "inside the catch block. i =" << i;
	}
}


void main() {
	foo();
}