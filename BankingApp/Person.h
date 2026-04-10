#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {


protected:

	string name = "";
	int age = 0;
	int acctNum = 0;

public:

	Person() : name(""), age(0), acctNum(0) {}

	string getName() const { return name; }
	int getAge() const { return age; }
	int getAcctNum() const { return acctNum; }

	void setName(string& n) { name = n; }
	void setAge(int a) { age = a; }
	void setAcctNum(int a) { acctNum = a; }

	//virtual ~Person();
	static int userAmt;

};

#endif