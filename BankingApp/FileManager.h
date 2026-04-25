#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "User.h"
#include "Manager.h"
#include "Transaction.h"

class FileManager {

public:

    static void removeUserFromIndex(int accountNumber);

    // USER CRUD
    static void saveUser(User& user);
    static User loadUser(int accountNumber);

    static void deleteUser(int accountNumber);

    // INDEX / IDS
    static void writeUserIndex(int acctNumber);
    static int getNextAccountNumber();
    static int countUsers();

    // TRANSACTIONS
    static void saveTransaction(int accountNumber, const Transaction& t);
    static void loadTransactions(int accountNumber, BankAccount& account);

    // MANAGER
    static Manager loadManager(int managerId);

    // UTILITIES
    static bool fileExists(const std::string& path);
};

#endif