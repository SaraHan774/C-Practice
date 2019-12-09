#include <iostream>

class Circle {
	public :
		double radius;
		double area(); 
};

double Circle::area() {
	return radius * radius * 3.14159;
}


class Cylinder : public Circle {
	public :
		double height;
		double volume();
};


double Cylinder::volume() {
	return area() * height;
}

void main() {
	Cylinder c;
	
	c.radius = 5.0;
	c.height = 10.0;

	std::cout << c.volume();
}
