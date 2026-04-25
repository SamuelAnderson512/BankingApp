#ifndef USER_H
#define USER_H

#include <string>
#include "Person.h"
#include "BankAccount.h"

class User : public Person {

protected:

	BankAccount userAcct;

public:
	User(const std::string&, const std::string& p, int an, double balance);


	BankAccount& getBankAccount();
	std::string getDirectoryFile() const override;
	std::string getRole() const override;
};



#endif