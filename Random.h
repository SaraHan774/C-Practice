/*
 * Random.h
 *
 *  Created on: Nov 1, 2019
 *      Author: sarah
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <iostream>
#include <cstdlib>

class Random{
private:
	int number;
public:
	Random();
	int getNumber();
	int next();
	int nextInRange(int from, int to);
};

#endif /* RANDOM_H_ */
