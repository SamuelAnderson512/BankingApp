#include "User.h"

User::User(const std::string& n,
	const std::string& p,
	int an,
	double balance)
	:Person(n, p, an),
	userAcct(balance)
{

}

BankAccount& User::getBankAccount() { return userAcct; }

std::string User::getDirectoryFile() const {
	return "Users/" + std::to_string(acctNum) + ".txt";
}

std::string User::getRole() const {
	return "User";
}