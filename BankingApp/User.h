#ifndef USER_H
#define USER_H

#include <string>
#include "BankAccount.h"
#include "Person.h"


class User : public Person {

private:
	BankAccount userAcct;

public:
	User(const string& n, int a, int an,
		const string& acctType, double balance)
		: Person(),
		userAcct(acctType, balance)
	{
		name = n;
		age = a;
		acctNum = an;
	}

};

#endif