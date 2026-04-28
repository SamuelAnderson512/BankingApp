#include "BankAccount.h"
// Default constructor
BankAccount::BankAccount()
    : balance(0.0), size(0), capacity(10)
{
    transactionList = new Transaction[capacity];
    ++activeAccounts;
}

// Copy constructor
BankAccount::BankAccount(const BankAccount& other)
    : balance(other.balance), size(other.size), capacity(other.capacity)
{
    transactionList = new Transaction[capacity];
    for (int i = 0; i < size; ++i) {
        transactionList[i] = other.transactionList[i];
    }
    ++activeAccounts;
}

// Assignment operator
BankAccount& BankAccount::operator=(const BankAccount& other)
{
    if (this != &other) {
        delete[] transactionList;
        balance = other.balance;
        size = other.size;
        capacity = other.capacity;
        transactionList = new Transaction[capacity];
        for (int i = 0; i < size; ++i) {
            transactionList[i] = other.transactionList[i];
        }
    }
    return *this;
}
#include <iostream>

int BankAccount::activeAccounts = 0;

BankAccount::BankAccount(double initialBalance)
    :balance(initialBalance), size(0), capacity(10)
{
    transactionList = new Transaction[capacity];
}
BankAccount::~BankAccount()
{
    delete[] transactionList;
    --activeAccounts;
}

double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::setBalance(double b)
{
    if (b < 0) {
        std::cerr << "Error: Cannot set negative balance.\n";
        balance = 0;
    }
    else {
        balance = b;
    }
}

void BankAccount::resize()
{
    int newCapacity = capacity * 2;

    Transaction* newList = new Transaction[newCapacity];

    for (int i = 0; i < size; i++) {
        newList[i] = transactionList[i];
    }

    delete[] transactionList;

    transactionList = newList;
    capacity = newCapacity;
}

int BankAccount::transact(const Transaction& t)
{
    // 1. update balance based on transaction type
    if (t.getType() == true) {
        balance += t.getAmount();
    }
    else if (t.getType() == false) {
        if (balance - t.getAmount() < 0) {
            std::cout << "Transaction Failed: Insufficient Funds\n";
            return 0;
        }

        balance -= t.getAmount();

    }
    if (balance < 0) {
        balance = 0;
        std::cerr << "Error: Balance went negative! Reset to zero.\n";
    }
    // 2. resize if needed
    if (size == capacity) {
        resize();
    }

    // 3. store transaction
    transactionList[size] = t;
    size++;
    return 1;
}

void BankAccount::loadTransaction(const Transaction& t)
{
    if (size == capacity) {
        resize();
    }

    transactionList[size++] = t;
}


void BankAccount::printTransactions() const
{
    std::cout << "---- Transaction History ----\n";

    if (size == 0) {
        std::cout << "No transactions found.\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        const Transaction& t = transactionList[i];

        std::cout << (t.getType() ? "Deposit: " : "Withdrawal: ")
            << t.getAmount() << "\n";
    }

    std::cout << "----------------------------\n";
}