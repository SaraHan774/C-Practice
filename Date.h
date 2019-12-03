/*
 * Date.h
 *
 *  Created on: Nov 1, 2019
 *      Author: sarah
 */

#ifndef DATE_H_
#define DATE_H_
#include <string>

class Date{

private:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int year, int month, int day);
	Date(std::string date);
	void show();
	int getYear();
	int getMonth();
	int getDay();
};


#endif /* DATE_H_ */
