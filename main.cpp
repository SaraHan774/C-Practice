//============================================================================
// Name        : november.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

//#include "Circle.h"
//#include "Tower.h"
//#include "Date.h"
//#include "Account.h"
//#include "Random.h"
#include "Histogram.h"

int main() {
//	cout << "Enter your address : " ;
//	char address[100];
//	cin.getline(address, 100, '\n');
//	//Enter - print
//
//	cout << "Your address is : " << address << endl;

//	Circle donut;
//	double area = donut.getArea();
//	cout << "The area of this circle is : " << area << endl;
//
//	Circle pizza(30);
//	area = pizza.getArea();
//	cout << "The area of this pizza is : " << area << endl;

//	Tower tower1;
//	Tower tower2(500);
//	tower1.getHeight();
//	tower2.getHeight();

//	Date today;
//	Date date1(1995, 8, 4);
//	Date date2("1997/3/14");
//
//	date2.show();
//	date1.show();

//	Account a("Han", 123, 5230.50);
//	a.deposit(30000);
//	cout << "Owner : " << a.getOwner() << endl;
//	cout << "Owner ID : " << a.getId() << endl;
//	a.inquiry();

//	Random r;
//	cout << "10 Random integers up to " << RAND_MAX << endl;
//	for(int i = 0; i < 10; i++){
//		int n = r.next();
//		cout << n << " " ;
//	}
//
//	cout << endl << endl << "Random Integers between 2 - 4 " << endl;
//
//	for(int i = 0; i < 10; i++){
//		int n = r.nextInRange(2, 4);
//		cout << n << " " ;
//	}
//
//	cout << endl;


	//new & delete
//	int *p;
//
//	p = new int;
//	if(!p){
//		cout << "Memory allocation failed. \n" ;
//		return 0;
//	}
//
//	*p = 5;
//	int n = *p;
//
//	cout << "*p = " << *p << endl;
//	cout << "n = " << n << endl;

//	int *p = new int[5];
//	if(!p){
//		return 0;
//	}
//	cout << p << endl;
//	for(int i = 0; i < 5; i++){
//		p[i] = i;
//		cout << "*p : " << *(p+i) << "  ";
//	}
//
//	delete [] p; //return the memory of the array
//
//	cout << *p << endl;

	Histogram elvisHisto("this is a sample string");
	elvisHisto.put("...another SAMPLE string");
	elvisHisto.putc('c');
	elvisHisto.print();
	cout << endl;

	return 0;
}
