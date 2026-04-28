#include "FileManager.h"
#include <iostream>
#include<fstream>
#include <cstdio>

//Test

void FileManager::removeUserFromIndex(int accountNumber)
{
	std::ifstream inFile("users/index.txt");
	std::ofstream outFile("users/temp.txt");

	int currentAcct;

	while (inFile >> currentAcct)
	{
		if (currentAcct != accountNumber)
		{
			outFile << currentAcct << "\n";
		}
	}

	inFile.close();
	outFile.close();

	std::remove("users/index.txt");
	std::rename("users/temp.txt", "users/index.txt");

	std::cout << "User removed from index.\n";
}

// USER CRUD
void FileManager::saveUser(User& user) {

	std::ofstream file(user.getDirectoryFile());

	file << user.getName() << "\n";
	file << user.getPass() << "\n";
	file << user.getAcctNum() << "\n";
	file << user.getBankAccount().getBalance() << "\n";
}

User FileManager::loadUser(int accountNumber) {

	std::ifstream file("users/" + std::to_string(accountNumber) + ".txt");

	if (!file.is_open()) {
		std::cout << "User file not found\n";
		return User("", "", -1, 0); // fallback "invalid user"
	}

	std::string name;
	std::string password;
	int acctNum;
	double balance;

	file >> name;
	file >> password;
	file >> acctNum;
	file >> balance;

	file.close();


	return User(name, password, acctNum, balance);
}

void FileManager::deleteUser(int accountNumber) {
	std::string userFile =
		"users/" + std::to_string(accountNumber) + ".txt";

	std::string transactionFile =
		"Transactions/" + std::to_string(accountNumber) + ".txt";

	std::remove(userFile.c_str());
	std::remove(transactionFile.c_str());
	removeUserFromIndex(accountNumber);

	std::cout << "User deleted.\n";
}

// INDEX / IDS
void FileManager::writeUserIndex(int acctNumber) {
	std::ofstream file("Users/index.txt", std::ios::app);
	file << acctNumber << "\n";
}

int FileManager::getNextAccountNumber() {
	std::ifstream file("users/index.txt");

	int last = 999;
	int temp;

	while (file >> temp) {
		last = temp;
	}

	return last + 1;
}

int FileManager::countUsers() {

	std::ifstream file("Users/index.txt");
	int count = 0;
	std::string line;


	if (!file.is_open()) {
		std::cout << "ERROR: usersindex.txt NOT FOUND\n";
		return 0;
	}


	while (getline(file, line)) {
		if (!line.empty()) count++;
	}

	return count;
}

/*void listUserInformation() {
	std::ifstream file("Users/index.txt");
	User user("","",0,0);

	std::string line;


	if (!file.is_open()) {
		std::cout << "ERROR: usersindex.txt NOT FOUND\n";
		return 0;
	}


	while (getline(file, line)) {
		
		if (!line.empty()){
		user = FileManager::loadUser(std::stoi(line));
		std::cout << user.getAcctNum() << user.getName() << user.getBankAcct().getBalance() << std::endl;	
		}
	}
	return;
}
*/

// TRANSACTIONS
void FileManager::saveTransaction(int accountNumber, const Transaction& t) {
	std::ofstream file("Transactions/" + std::to_string(accountNumber) + ".txt", std::ios::app);


	file << (t.getType() ? 1 : 0) << " " << t.getAmount() << "\n";


}
void FileManager::loadTransactions(int accountNumber, BankAccount& account)
{
	std::ifstream file("Transactions/" + std::to_string(accountNumber) + ".txt");

	if (!file.is_open()) return;

	int type;
	double amount;

	while (file >> type >> amount)
	{
		Transaction t(amount, type == 1);
		account.loadTransaction(t);
	}
}

// MANAGER
Manager FileManager::loadManager(int managerId) {

	std::ifstream file("Managers/" + std::to_string(managerId) + ".txt");

	if (!file.is_open()) {
		std::cout << "Manager file not found\n";
		return Manager("", "", -1); // fallback "invalid user"
	}

	std::string name;
	std::string password;
	int acctNum;

	file >> name;
	file >> password;
	file >> acctNum;

	file.close();


	return Manager(name, password, acctNum);

}

// UTILITIES
bool fileExists(const std::string& name) {
	std::ifstream f(name.c_str());
	return f.good(); // Returns true if the file was opened successfully
}