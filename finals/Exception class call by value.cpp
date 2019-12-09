#include <iostream>

class Exception {
public:
	int code;
	Exception(int i) {
		code = i;
	}
};

void foo() {
	try {
		throw Exception(1);
	}
	catch (Exception e) {
		std::cout << e.code;
	}
}

void main() {
	foo();
}