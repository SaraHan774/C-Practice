/*
 * Rectangle.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: sarah
 */

#include <iostream>
using namespace std;

class Rectangle{

public:
	int width;
	int height;
	int getArea();
};

int Rectangle::getArea(){
	return width * height;
}


