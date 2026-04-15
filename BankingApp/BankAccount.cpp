#include <iostream>
#include <string>
#include <fstream>
#include "Transaction.h"

using namespace std;


class BankAccount {
private:

	string accountType;
	double balance;
	int transactionCount = 0;

	Transaction tList[100];

public:

	BankAccount(string a, double b) { accountType = a; balance = b; }
	//~BankAccount();

	string getaccountType() { return accountType; }
	double getBalance() { return balance; }

	void setaccountType(string s) { accountType = s; }
	void setBalance(double b) { balance = b; }

	void transact(Transaction t) {
		if (t.getType() == 1) {
			cout << "EPIC BACON DEPOSIT\n";
			balance = balance + t.gettAmt();
		}
		if (t.getType() == 2) {
			cout << "EPIC BACON WITHDRAW\n";
			balance = balance - t.gettAmt();
		}


	}


};