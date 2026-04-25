#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {

protected:
	std::string name;
	std::string password;
	int acctNum;

public:



	Person(const std::string& n, const std::string& p, int an);

	virtual ~Person();

	std::string getName() const;
	std::string getPass() const;
	int getAcctNum() const;

	void setName(const std::string& n);
	void setPass(const std::string& p);
	void setAcctNum(int an);

	virtual std::string getDirectoryFile() const = 0;
	virtual std::string getRole() const = 0;

};

#endif