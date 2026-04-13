#include <string>
using namespace std;

class Person {


protected:

	string name = "";
	int acctNum = 0;

public:

	Person() : name(""),  acctNum(0) {}

	Person(string n, int an) {
	
		name = n;
		acctNum = an;
	
	};

	string getName() const { return name; }
	int getAcctNum() const { return acctNum; }

	void setName(string& n) { name = n; }
	void setAcctNum(int a) { acctNum = a; }

	//virtual ~Person();
	static int userAmt;

};