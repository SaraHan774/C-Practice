/*
 * Account.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: sarah
 */

#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(){
	owner = "anonymous";
	id = 0;
	balance = 0.0;
}

Account::Account(string _owner, int _id, double _balance){
	owner = _owner;
	id = _id;
	balance = _balance;
}

void Account::deposit(double money){
	balance += money;
}

void Account::withdraw(double money){
	balance -= money;
}

void Account::inquiry(){
	cout << "Your Balance is : $" << balance << endl;
}

string Account::getOwner(){
	return owner;
}

int Account::getId(){
	return id;
}

double Account::getBalance(){
	return balance;
}


