/*
 * Account.h
 *
 *  Created on: Nov 1, 2019
 *      Author: sarah
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>

class Account{
private:
	std::string owner;
	int id;
	double balance;

public:
	Account();
	Account(std::string owner, int id, double balance);
	void deposit(double money);
	void withdraw(double money);
	void inquiry();
	std::string getOwner();
	int getId();
	double getBalance();
};



#endif /* ACCOUNT_H_ */
