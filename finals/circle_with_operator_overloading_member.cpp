#include <iostream>

class Circle {
	private :
		double radius;
	public : 	
		double get_radius() const; 
		Circle(double r); // Constructor
		const Circle operator+ (const Circle &other) const;
		friend std::ostream & operator<<(std::ostream & os, const Circle c);
};

const Circle Circle::operator+ (const Circle &other) const {
	Circle c = *this;
	c.radius += other.radius;
	return c;
}

std::ostream & operator<<(std::ostream & os, const Circle c) {
	os << "radius:" << c.radius;
	return os;
}


Circle::Circle(double radius){
	this -> radius = radius;
}

double Circle::get_radius() const {
	return radius;
}

void main() {
	Circle c1 = Circle(5.0); 
	Circle c2 = Circle(3.0); 

	std::cout << (c1 + c2).get_radius() << std::endl;
	std::cout << c1 << std::endl;
}