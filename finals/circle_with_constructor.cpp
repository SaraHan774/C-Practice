#include <iostream>

class Circle {
	public : 
		double radius;
		double area(); 
		Circle(double r); // Constructor
		Circle(); // Default Constructor
		~Circle(); // Destructor
};

Circle::Circle(){ // Default Constructor Definition
	radius = 0;
}

Circle::Circle(double r){
	radius = r;
}

Circle::~Circle(){
	std::cout << "Goodbye Object\n";
}

double Circle::area() {
	return radius * radius * 3.14159;
}

void main() {
	Circle c = Circle(5.0); // we use our constuctor

	std::cout << c.area() << "\n";
}
