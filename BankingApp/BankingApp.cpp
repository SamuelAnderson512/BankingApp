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


				while (getline(inputFile, line)) {


					if(line.find(number) != string::npos) {
						cout << line << endl;
						for (int i = 0; i < 2; i++) {
							if (getline(inputFile, line)) {
								cout << line << endl;
							}
						}
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

			cout << "Enter Account Number(5 digits)" << endl;
			cin.ignore();        // clear leftover newline
			getline(cin, account);

			cout << "Enter Password" << endl;
			getline(cin, login);

			cout << "Enter Name" << endl;
			getline(cin, name);


			ofstream outputFile("example.txt", ofstream::app);

			if (outputFile.is_open()) {

				outputFile << "Account#: " << account << endl;
				outputFile << "Login info: " << login << endl;
				outputFile << "Name: " << name << endl;

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

	start();

	
	return 0;
}