/*
 * Random.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: sarah
 */

#include "Random.h"

//rand() % M을 하면 0~(M-1)까지의 수가 생성된다.
//rand() % M + N을 하면 N~(M+N-1)까지의 수가 생성된다.


Random::Random(){
	number = 0;
}


int Random::next(){
	number = rand();
	return number;
}

int Random::nextInRange(int from, int to){
	number = rand() % (to - from + 1) + from;
	return number;
}

int Random::getNumber(){
	return number;
}
