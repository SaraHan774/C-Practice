#include <iostream>

//V
class Circle {
	public : 
		double radius;
		double area(); 
};

double Circle::area() {
	return radius * radius * 3.14159;
}

void main() {
	Circle c;

	c.radius = 5.0;
	std::cout << c.area();
}
