/*
 * Histogram.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: sarah
 */

#include "Histogram.h"
using namespace std;

int Histogram::charCount = 0;

Histogram::Histogram(){
	text = "";
	initAccAry(accumulation);
}

Histogram::Histogram(string s){
	text = s;
	initAccAry(accumulation);
	Histogram::put(s);
}


void Histogram::pushChar(char c){
	if(c >= 'A' && c <= 'Z'){
		//convert to lower case ascii
		c += DIFF;
		accumulation[c - 'a']++;
	}else if(c >= 'a' && c <= 'z'){
		accumulation[c - 'a']++;
	}
	charCount++;
}

void Histogram::put(string s){
	text.append(s);

	for(size_t i = 0; i < s.length(); i++){
		Histogram::pushChar(s[i]);
	}
}


void Histogram::putc(char c){
	text.append(1, c);
	Histogram::pushChar(c);
}

void Histogram::print(){
	cout << text << endl << endl;

	cout << "total number of characters : " << charCount << endl << endl;
	for(int i = 0; i <= 'z' - 'a'; i++){
		cout << char(i + 'a') << '(' << accumulation[i] << ") : ";
		for(int j = 0; j < accumulation[i]; j++){
			cout << "*";
		}
		cout << endl;
 	}
}


//initialize the array to 0
void Histogram::initAccAry(int *acc){
	for(int i = 0; i < MAX_ARR_SIZE; i++){
		acc[i] = 0;
	}
}
