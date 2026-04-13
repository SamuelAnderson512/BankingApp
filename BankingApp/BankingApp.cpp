#include <iostream>
#include <string>
#include <fstream>

#include "Person.h"
#include "BankAccount.h"
#include "Transaction.h"
#include "User.h"



using namespace std;

class Manager : public Person {

private:

public:

};


string extractValue(const string& line) {
	size_t pos = line.find(":");
	if (pos == string::npos) return "";

	string value = line.substr(pos + 1);

	// remove leading space
	if (!value.empty() && value[0] == ' ')
		value.erase(0, 1);

	return value;
}


void userLogin() {
	bool running = true;


	while (running) {

		//cout << Welcome object.name
		
		// 1. Make a transaction, 2. Make a Deposit, 3. Exit

		//if 1 { object.balance = object.balance - transaction, example.txt balance changed}

		// if 2 { object.balance = object.balance + deposit, example.txt balance changed}

		// if 3 running = false;

	}

}



void start() {

	bool running = true;

	while (running) {

		int response = 0;

		cout << "1. User Login\n2. Create Account\n3. Manager Login\n4. Exit\n";

		cin >> response;

		if (response == 1) {

			cout << "One Picked" << endl;
			string number = "";

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

						/*
						User* u = new User(
							name,
							login,
							account,
							accountType,
							balance
						);


						cout << u->getName() << endl;

						delete u;

						*/
					}


				}
				// Close the file after reading
				inputFile.close();
			}
			else {
				cout << "Unable to open the file for reading." << endl;
			}
		}

		if (response == 2) {
			cout << "Two Picked" << endl;

			string account = "";
			string login = "";
			string name = "";
			string balance ="";
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
					cout << "Account Number already exists"<<endl;
					continue;
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
		if (response == 3) { cout << "Three Picked"; }
		if (response == 4) {
		

			cout << "Exiting...\n";
			running = false;

		}

	}

}




int main() {

/*
	User* u = new User("John Smith",
		"mypassword",
		12345,
		"Checking",
		1500.00);

	cout << u->getAcctNum() << endl;

	delete u;
*/

	start();

	
	return 0;
}