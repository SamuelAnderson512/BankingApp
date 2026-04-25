#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {

protected:
    double amount;
    bool type;

public:

    Transaction() : amount(0.0), type(true) {}
    Transaction(double amt, bool t)
        : amount(amt), type(t) {
    }

    double getAmount() const { return amount; }
    bool getType() const { return type; }

    void setAmount(double amt) { amount = amt; }
    void setType(bool t) { type = t; }

};

#endif

