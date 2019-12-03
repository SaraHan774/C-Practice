/*
 * Histogram.h
 *
 *  Created on: Nov 5, 2019
 *      Author: sarah
 */

#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

#include <string>
#include <iostream>
#include <cstddef>
#define MAX_ARR_SIZE 30
#define DIFF ('a' - 'A')


class Histogram{
private:
	std::string text;
	int accumulation[MAX_ARR_SIZE];

public:
	static int charCount;
	Histogram();
	Histogram(std::string s);
	void putc(char c);
	void put(std::string s); //put -> sorting
	void print();
	void initAccAry(int *accumulation);
	void pushChar(char c);
};



#endif /* HISTOGRAM_H_ */
