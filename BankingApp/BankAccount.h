#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "Transaction.h"

using namespace std;


class BankAccount {
private:

	string accountType;
	double balance;

	Transaction tList[100];

public:

	BankAccount(string a, double b) { accountType = a; balance = b; }
	//~BankAccount();

	string getaccountType() { return accountType; }
	double getBalance() { return balance; }

	void setaccountType(string s) { accountType = s; }
	void setBalance(double b) { balance = b; }
	void setBalance(double b, double e) { balance = b + e; }


};

#endif