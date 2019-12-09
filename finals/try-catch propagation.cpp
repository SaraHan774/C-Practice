#include <iostream>

void foo_1() {
	if (1) {
		// the catch clause for the throw statement is in foo
		throw 1;
	}
}

void foo() {
	try {
		foo_1();
	}
	catch (int i) {
		std::cout << "inside the catch block. i =" << i;
	}
}


void main() {
	foo();
}