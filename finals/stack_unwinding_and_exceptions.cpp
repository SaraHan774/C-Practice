#include <iostream>

class Exception {
public:
	int code;
	Exception(int i) {
		std::cout << "Creation of Exception object\n";
		code = i;
	}
	~Exception(){
		std::cout << "Destruction of Exception object\n";
	}
};

void foo() {
	try {
		throw Exception(1); // local object !
	}
	catch (Exception &e) {
		// BIG PROBLEM: e has already been destructed when we come here
		std::cout << "Access to the Exception object:" 
			<< e.code << std::endl;
	}
}

void main() {
	foo();
}