#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include "Transaction.h"

class BankAccount {

protected:
	Transaction* transactionList;
	int size;
	int capacity;
	double balance;

	void resize();

public:
	BankAccount(double initialBalance);
	~BankAccount();

	double getBalance() const;
	void setBalance(double b);

	int transact(const Transaction& t);

	void loadTransaction(const Transaction& t);

	void printTransactions() const;


};


#endif