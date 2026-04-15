#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

using namespace std;

class Transaction {

private:

	double tAmt = 0;
	int type = 0;

public:

	Transaction() { tAmt = 0, type = 0; }

	Transaction(double a, int t) { tAmt = a, type = t; }

	int gettAmt() {
		return tAmt;
	}

	int getType() {
		return type;
	}

};

#endif