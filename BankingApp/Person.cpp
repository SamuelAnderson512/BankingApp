#include <string>
using namespace std;

class Person {


protected:

	string name = "";
	string password = "";
	int acctNum = 0;

public:

	Person() : name(""), password(""), acctNum(0) {}

	Person(string n, string p, int an) {

		name = n;
		password = p;
		acctNum = an;

	};

	string getName() const { return name; }
	string getPass() const { return password; }
	int getAcctNum() const { return acctNum; }

	void setName(string& n) { name = n; }
	void setPass(string& p) { password = p; }
	void setAcctNum(int a) { acctNum = a; }

	static int userAmt;

};