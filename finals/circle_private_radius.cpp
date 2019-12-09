#include <iostream>

//V
class Circle {
	private : 
		double radius;
	public :
		double area();
		void set_radius(double r);
};

void Circle::set_radius(double r) {
	radius = r;
}

double Circle::area() {
	return radius * radius * 3.14159;
}

void main() {
	Circle c;

	c.set_radius(5.0);
	std::cout << c.area();
}
