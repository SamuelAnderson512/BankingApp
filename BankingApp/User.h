#ifndef USER_H
#define USER_H

#include <string>
#include "BankAccount.h"
#include "Person.h"


class User : public Person {

private:
	BankAccount userAcct;
	string password;


public:
	User(const string& n,
		string p, int an,
		const string& acctType,
		double balance)

		: Person(n, an),
		userAcct(acctType, balance),
		password(p)
	{
	}

	int getBalance() {
		return userAcct.getBalance();
	}

};

#endif