#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Person.h"
#include "BankAccount.h"
#include "Transaction.h"
#include "User.h"

using namespace std;

class Manager : public Person {

private:

public:

};


int countUsers() {
	ifstream file("Users/usersindex.txt");
	int count = 0;
	string line;


	if (!file.is_open()) {
		cout << "ERROR: usersindex.txt NOT FOUND\n";
		return 0;
	}


	while (getline(file, line)) {
		if (!line.empty()) count++;
	}

	return count;
}


//helper function to check if a file exists or not
bool fileExists(const string& name) {
	ifstream f(name.c_str());
	return f.good(); // Returns true if the file was opened successfully
}

void fileEdit(string a, string n, string p, string b, string t) {

	string filePath = "Users/" + a + ".txt";

	if(fileExists(filePath)){

	ofstream MyFile("Users/" + a + ".txt");
	MyFile << a << endl;
	MyFile << n << endl;
	MyFile << fixed << setprecision(2) << stod(b) << endl;
	MyFile << p << endl;
	MyFile << t << endl;
	MyFile.close();
	}

	else {
		cout << " File does not exist\n";
	}
}

string extractValue(const string& line) {
	size_t pos = line.find(":");
	if (pos == string::npos) return "";

	string value = line.substr(pos + 1);

	// remove leading space
	if (!value.empty() && value[0] == ' ')
		value.erase(0, 1);

	return value;
}

void userCreation(){
	cout << "Two Picked" << endl;

	string account = "";
	string login = "";
	string name = "";
	string balance = "";
	string accountType = "";

	bool accountExists = 0;

	cout << "Enter Account Number(5 digits)" << endl;
	cin.ignore();        // clear leftover newline
	getline(cin, account);

	//############

	ifstream inputFile("example.txt");
	if (inputFile.is_open()) {
		cout << "RF: ";
		// Read and display each line from the file
		string line;

		while (getline(inputFile, line)) {
			if (line.find("Account#: " + account) != string::npos) {
				accountExists = true;
				break;
			}
		}

		if (accountExists) {
			cout << "Account Number already exists" << endl;
			return;
		}

		// Close the file after reading
		inputFile.close();
	}
	else {
		cout << "Unable to open the file for reading." << endl;
	}

	//##############

	cout << "Enter Password" << endl;
	getline(cin, login);

	cout << "Enter Name" << endl;
	getline(cin, name);

	cout << "Enter Account Type" << endl;
	getline(cin, accountType);

	cout << "Enter Balance" << endl;
	getline(cin, balance);

	ofstream outputFile("example.txt", ofstream::app);

	//Bread and Butter of New File Creation System
	ofstream MyFile("Users/"+account+".txt");
	fileEdit(account, name, login, balance, accountType);
	MyFile.close();
	cout << fileExists("Users/" + account + ".txt") << endl;



	std::ofstream file("Users/usersindex.txt", std::ios::app);

	if (!file.is_open()) {
		std::cout << "Failed to open file\n";
	}

	file << account << endl;
	file.close();

	if (outputFile.is_open()) {

		outputFile << "Account#: " << account << endl;
		outputFile << "Login info: " << login << endl;
		outputFile << "Name: " << name << endl;
		outputFile << "Balance: " << balance << endl;
		outputFile << "Account Type: " << accountType << endl;

		outputFile.close();
		cout << "Data written to the file successfully." << endl;
	}
	else {
		cout << "Unable to open the file for writing." << endl;
	}

}

void managerLogin() {}

void userLogin() {

	cout << "One Picked" << endl;
	string number = "";

	cout << "Enter your Account Number\n";
	cin >> number;

	ifstream inputFile("example.txt");
	if (inputFile.is_open()) {
		cout << "Reading data from the file:" << endl;
		// Read and display each line from the file
		string line;

		//begin reading the whole file
		while (getline(inputFile, line)) {

			//if we find the account number in the file.

			if (line.find("Account#: " + number) != string::npos) {

				int account = stoi(extractValue(line));
				string login;
				string name;
				int balance = 0;
				string accountType;

				cout << line << endl;

				for (int i = 0; i < 4; i++) {
					if (getline(inputFile, line)) {
						cout << line << endl;

						string value = extractValue(line);

						if (i == 0)      login = value;
						else if (i == 1) name = value;
						else if (i == 2) balance = stoi(value);
						else if (i == 3) accountType = value;
					}
				}

				//Test Code showing objects can be initialized from the file.


				User* u = new User(
					name,
					login,
					account,
					accountType,
					balance
				);

				int input = 0;
				double depot = 0;

				cout << "Hello " << u->getName() << endl;
				cout << u->getBalance() << endl;
				cout << "What Action Would You Like to Complete?\n";
				cout << "1. Make A Deposit\n";
				cout << "2. Make A Withdrawal\n";
				cout << "3. Exit\n";

				

				cin >> input;
				if (input == 1) { 
					cout << "Enter Deposit Amount\n";
					cin >> depot;
					
					Transaction tran = Transaction(depot, input);

					u->transact(tran);

					double newBalance = u->getBalance();
					u->setBalance(newBalance);
					cout << "Your New Balance is: \n";
					cout << newBalance<<endl;

					fileEdit(to_string(account),name,login,to_string(newBalance),accountType);

				
				}
				if (input == 2) {}
				if (input == 3) {}

				delete u;


			}


		}
		// Close the file after reading
		inputFile.close();
	}
	else {
		cout << "Unable to open the file for reading." << endl;
	}

}



void start() {

	bool running = true;

	while (running) {

		int response = 0;

		cout << "1. User Login\n2. Create Account\n3. Manager Login\n4. Exit\n";

		cin >> response;

		if (response == 1) {
			userLogin();
		}

		if (response == 2) {
			userCreation();
		}
		if (response == 3) { cout << "Three Picked\n"; }
		if (response == 4) {
		
			cout << "Exiting...\n";
			running = false;

		}

	}

}




int main() {
	cout << countUsers() << endl;

	start();

	
	return 0;
}