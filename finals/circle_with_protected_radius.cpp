#include <iostream>

class Circle {
	protected : // change this line to pivate and check the effect!
		double radius;
	public :
		double area(); 
};

double Circle::area() {
	return radius * radius * 3.14159;
}


class Cylinder : public Circle {
	private :
		double height;
	public :
		double volume();
		Cylinder(double r, double h);
};


Cylinder::Cylinder(double r, double h) {
	radius = r; // OK, because radius is protected
	height = h;
}


double Cylinder::volume() {
	return area() * height;
}

void main() {
	Cylinder c(10 ,5);

	std::cout << c.volume();
}
