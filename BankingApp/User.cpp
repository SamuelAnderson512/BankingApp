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

//Use of A pure virtual Method derived from the Person class
std::string User::getDirectoryFile() const {
	return "Users/" + std::to_string(acctNum) + ".txt";
}

std::string User::getRole() const {
	return "User";
}