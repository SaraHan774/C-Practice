#include <iostream>

class Circle {
	protected : // change this line to pivate and check the effect!
		double radius;
	public :
		Circle();
		Circle(double r);
		double area(); 
};

Circle::Circle() {
	radius = 0;
}

Circle::Circle(double r) {
	radius = r;
}

double Circle::area() {
	return radius * radius * 3.14159;
}


class Cylinder : public Circle {
	private :
		double height;
	public :
		double volume();
		double area(); 
		Cylinder(double r, double h);
};


Cylinder::Cylinder(double r, double h) : Circle(r) { // We call the Circle Constructor
	height = h;
}


double Cylinder::volume() {
	return area() * height;
}

// here we override the area method from Circle
double Cylinder::area() { 
	return (Circle::area()) * 2 
		+ (2 * radius * 3.14159);
}

void main() {
	Cylinder c(10 ,5);

	std::cout << c.area();
}
