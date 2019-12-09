#include <iostream>

class Circle {
	private :
		double radius;
	public : 	
		double get_radius(); 
		Circle(double r); // Constructor
		friend Circle operator+(const Circle c1, const Circle c2);
		friend std::ostream & operator<<(std::ostream & os, const Circle c);
};

// We define an operator + for Circle
Circle operator+(const Circle c1, const Circle c2) {
	return Circle(c1.radius + c2.radius);
}

std::ostream & operator<<(std::ostream & os, const Circle c) {
	os << "radius:" << c.radius;
	return os;
}


Circle::Circle(double radius){
	this -> radius = radius;
}

double Circle::get_radius() {
	return radius;
}

void main() {
	Circle c1 = Circle(5.0); 
	Circle c2 = Circle(3.0); 

	std::cout << (c1 + c2).get_radius() << std::endl;
	std::cout << c1 << std::endl;
}
