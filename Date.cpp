/*
 * Date.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: sarah
 */

#include <iostream>
using namespace std;

#include "Date.h"
#define LOG(x) cout<<x<<endl

	Date::Date(){
		year = 2019;
		month = 10;
		day = 31;
	}

	Date::Date(int y, int m, int d){
		year = y;
		month = m;
		day = d;
	}

	Date::Date(string date){
		size_t i = 0, j = 0, k = 0;
		int arr[4];
		while(i < date.length() + 1){
			if(date[i] == '/' || i == date.length()){
				string s = date.substr(j, i-j);
				arr[k] = stoi(s);
				j = i + 1;
				k++;
			}
			i++;
		}
		year = arr[0];
		month = arr[1];
		day = arr[2];
	}

	int Date::getYear(){
		return year;
	}

	int Date::getMonth(){
		return month;
	}

	int Date::getDay(){
		return day;
	}

	void Date::show(){
		cout << "yyyy/mm/dd : " << year
			<< "/" << month << "/" << day << endl;
	}

