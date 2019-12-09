#include <iostream>

using namespace std;

template <long N> 
class Factorial { 
public: 
	long Value(void) { 
		return N * fn_1.Value(); 
	} 
private: 
	Factorial<N-1> fn_1; 
};

template <> 
class Factorial<0> { 
public: 
	long Value(void) { return 1; } 
}; 

void main() {
	Factorial<15> f; 
	cout << f.Value() << endl;
}