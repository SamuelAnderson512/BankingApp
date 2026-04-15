#include <string>
#include "BankAccount.h"
#include "Person.h"


class User : public Person {

private:
	BankAccount userAcct;


public:
	User(const string& n,
		string p, int an,
		const string& acctType,
		double balance)

		: Person(n, p, an),
		userAcct(acctType, balance)
	{
	}

	string getaccountType() { return userAcct.getaccountType(); }

	double getBalance() {
		return userAcct.getBalance();
	}

	void setBalance(double b) {
		userAcct.setBalance(b);
	}

	void transact(Transaction t) {
		userAcct.transact(t);
	}

};