#include <string>
#include <iostream>
#include "Manager.h"
#include "FileManager.h"

Manager::Manager(
	const std::string& n,
	const std::string& p,
	int an)
	:Person(n, p, an)
{

}

int Manager::userAmt = FileManager::countUsers();


//Use of A pure virtual Method derived from the abstract Person class
std::string Manager::getDirectoryFile() const {
	return "Managers/" + std::to_string(acctNum) + ".txt";

}

//Use of A pure virtual Method derived from the abstract Person class
std::string Manager::getRole() const {
	return "Manager";
}

void Manager::deleteUser(int userNumber) {

	FileManager::deleteUser(userNumber);
	Manager::userAmt = FileManager::countUsers();
	std::cout << "Deleted\n";
}

void Manager::updateActiveUsers() {
	Manager::userAmt = FileManager::countUsers();
}

int Manager::getActiveAccounts() {
	//Call fileManager to read index
	//Placeholder
	Manager::userAmt = FileManager::countUsers();
	return userAmt;
}

