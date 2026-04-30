#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {

protected:
    double amount;
    bool type;

public:

    Transaction() : amount(0.0), type(true) {}


    Transaction(double amt, bool t)
        :type(t) {

        if (amt < 0)
            amount = 0;
        else
            amount = amt;
    }

    double getAmount() const { return amount; }
    bool getType() const { return type; }

    void setAmount(double amt) {
        if (amt < 0)
            amount = 0;
        else
            amount = amt;
    }
    void setType(bool t) { type = t; }

};

#endif

