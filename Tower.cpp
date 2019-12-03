
/*
 * Tower.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: sarah
 */

#include <iostream>
using namespace std;

#include "Tower.h"

Tower::Tower(){
	height = 1;
}

Tower::Tower(int h){
	height = h;
}

int Tower::getHeight(){
	cout << "The height of this tower is : " << height << endl;
	return height;
}
