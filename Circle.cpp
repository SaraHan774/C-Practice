/*
 * Circle.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: sarah
 */

#include <iostream>
using namespace std;

#include "Circle.h"

Circle::Circle(){

	radius = 1;
	cout << "Radius : " << radius;
	cout << " Making Circle ..." << endl;
}

Circle::Circle(int r){
	radius = r;
	cout << "Radius : " << radius;
	cout << " Making Circle ..." << endl;
}

double Circle::getArea(){
	return 3.14*radius*radius;
}
