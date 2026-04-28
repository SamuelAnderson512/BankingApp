#include <iostream>
#include "Manager.h"
#include "User.h"
#include "Transaction.h"
#include "FileManager.h"
#include <string>

//Debug User and Manager(DO NOT USE UNLESS YOU KNOW THE ACCT NUMBER HAS BEEN REMOVED)
//User user("Samuel", "Password", 999, 10000);
//Manager manny("Garret", "P@$$", 999);

void userOperations(User& user) {
    bool running = true;
    int choice;
    double transactionAmt = 0;
    std::cout << "Hello "<<user.getRole() <<": "<<user.getName() << std::endl;
    std::cout << "Your Balance is: " << user.getBankAccount().getBalance() << std::endl;
    while (running) {
        transactionAmt = 0;

        std::cout << "1: Make a Deposit" << std::endl;
        std::cout << "2: Make a Withdrawal" << std::endl;
        std::cout << "3: Exit" << std::endl;
        std::cout << "4: Show Transactions" << std::endl;

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            std::cout << "How Large?\n";

            if (!(std::cin >> transactionAmt)||transactionAmt < 0) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid amount\n";
                break;
            }

            Transaction t(transactionAmt, true);
            user.getBankAccount().transact(t);
            FileManager::saveTransaction(user.getAcctNum(), t);
            FileManager::saveUser(user);

            break;
        }
        case 2: {
            std::cout << "How Large?\n";
            std::cin >> transactionAmt;
            if (transactionAmt > 0){
                Transaction t(transactionAmt, false);
                user.getBankAccount().transact(t);
                FileManager::saveUser(user);
                FileManager::saveTransaction(user.getAcctNum(), t);
            }
            else { std::cout << "Transaction Error: Negative Number Entered\n"; }

            /*
            if (check == 1) {
                //Call File Manager to update users file, and transaction history
            }
            */
            //We will either be returned a success or failure(we cannot take money that isnt there.)

            break;
        }
        case 3:
            running = false;
            break;
        case 4:
            user.getBankAccount().printTransactions();
            break;
        default:
            std::cout << "Invalid choice\n";
            break;
        }

    }

}

void managerOperations(Manager& man) {

    bool running = true;
    int choice;
    int userAcctNum;
    int deletionCertainty = 0;

    std::cout << "Hello "<< man.getRole()<<": " << man.getName() << std::endl;
    while (running) {
        choice = 0;
        std::cout << "1: Delete a User" << std::endl;
        std::cout << "2:  Check Active Users" << std::endl;
        std::cout << "3: Exit" << std::endl;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {

        case 1: {
            std::cout << "Enter User's Account Number\n";
            std::cin >> userAcctNum;
            std::cout << "Are you Certain you want to delete: " << std::to_string(userAcctNum) << std::endl;
            std::cout << "Enter 1 for Yes and anything else for No: " << std::endl;
            std::cin >> deletionCertainty;

            if (deletionCertainty == 1){
            man.deleteUser(userAcctNum);
            }

            else { std::cout << "Your Response was not 1: User will not be deleted" << std::endl; }
            break;
        }

        case 2: {

            man.getActiveAccounts();

            break;
        }

        case 3: {

            running = false;

            break;
        }

        }

    }
}

void userLoginUi() {
    bool running = true;
    int accountNumber = 0;
    std::string pass = "";
    while (running) {

        std::cout << "User Login Chosen" << std::endl;
        std::cout << "Enter Your Account Number" << std::endl;
        std::cout << "Type -1 to Leave" << std::endl;
        std::cin >> accountNumber;
        std::cout << "Enter Your Password" << std::endl;
        std::cin >> pass;

        User user = FileManager::loadUser(accountNumber);

        if (user.getAcctNum() == -1) {
            std::cout << "Invalid user\n";
            return;
        }

        else if (pass != user.getPass() || pass == "") {
            return;
        }

        FileManager::loadTransactions(user.getAcctNum(), user.getBankAccount());

        userOperations(user);
        return;

        //FileManager Searches User Index for Account Number
        //IfFound load user class from file using FileManager
               //userOperations() called with user object passed through
        //Elseif -1 typed: return
        //Else try again
        //return called right after since we assume when they are done with their account that they aren't going to log in again


    }

}
void userCreateUi() {

    int accountNumber = 1001;
    std::string name = "";
    std::string password = "";
    double balance = 0;
    //check what the next account number can be and assign it to a variable
    //get the users name
    std::cout << "Enter your Name: \n";
    std::cin >> name;
    //get the balance
    std::cout << "Enter your Password: \n";
    std::cin >> password;
    //get a password
    std::cout << "Enter your Balance: \n";
    std::cin >> balance;
    //create user object
    User current(name, password, FileManager::getNextAccountNumber(), balance);
    std::cout << "Account Created for " << current.getName() << std::endl;
    FileManager::saveUser(current);
    FileManager::writeUserIndex(current.getAcctNum());
    //Call file manager to write user object into a file
    //Move to login(We will need to end the loop end the function, then move to login)
    //We need to return a value so we know whetehr we normal made an account or exited
    std::cout << current.getName() << std::endl;
    std::cout << current.getAcctNum() << std::endl;
    std::cout << current.getPass() << std::endl;
    std::cout << current.getBankAccount().getBalance() << std::endl;

}
void managerUi() {

    bool running = true;
    int accountNumber = 0;
    std::string pass = "";
    while (running) {

        std::cout << "Manager Login Chosen" << std::endl;
        std::cout << "Enter Your Account Number" << std::endl;
        std::cout << "Type -1 to Leave" << std::endl;
        std::cin >> accountNumber;
        std::cout << "Enter Your Password" << std::endl;
        std::cin >> pass;

        if (accountNumber == -1) { return; }

        Manager man = FileManager::loadManager(accountNumber);

        if (man.getAcctNum() == -1 || pass != man.getPass() || man.getPass() == "") {
            return;
        }

        else{
        managerOperations(man);
        return;
        }
        //check active user amount
            //Have fileManager count how many lines are in userindex and return
        //Remove User Account
            //Enter in a user acctNumber
            // check if account number exists
            //confirm screen
            //call on fileManger to delete user from index, delete transaction history, and delete user account
    }
}

void ui() {
    bool running = true;
    int choice = 0;

    while (running) {

        std::cout << "Welcome to Sam and Peyton's Banking Application" << std::endl;
        std::cout << "Choose an Option:" << std::endl;
        std::cout << "1: User Login" << std::endl;
        std::cout << "2: Manager Login" << std::endl;
        std::cout << "3: User Creation" << std::endl;
        std::cout << "4: Exit" << std::endl;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "You picked User Login" << std::endl;
            userLoginUi();
            break;
        case 2:
            std::cout << "You picked Manager Login" << std::endl;
            managerUi();
            break;
        case 3:
            std::cout << "You picked User Creation" << std::endl;
            userCreateUi();
            break;
        case 4:
            running = false;
            break;
        default:
            std::cout << "Unsure of your Answer, Please try again" << std::endl;
            break;
        }

    }
}


int main()
{

    //FileManager::saveUser(user);
    ui();
}

