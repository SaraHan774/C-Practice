#include <iostream>
// Problem 2a)
class Exception {
public:
	int code;
	/* Constructor */
	Exception( int code )
	{
		this->code = code;
	}
	/* Option */
	void what( void ) {
		std::cout << "Problem has code: " << code << std::endl;
	}
};
void fun() {
	try {
		std::cout << "FA\n";
		// throw Exception(3); // Problem 2b)
		// throw new Exception(3); // Problem 2d) 
		throw true;
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
	// Problem 2c)
	catch( Exception &e ) { // catch by reference
		e.what();
	}
	// Problem 2d)
	catch( Exception *e ) { // catch by pointer
		 e->what(); // equal to (*e).what();
		 delete e; // if we forget this, we have a memory leak
		 // the risk of this memory leak can be avoided via catching by reference
	}
	catch (...) { 
		std::cout << "E\n";
	}
	std::cout << "F\n";

    return 0;
}







