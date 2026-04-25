#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "Person.h"

class Manager : public Person {

protected:

public:
	Manager(const std::string&, const std::string& p, int an);

	void deleteUser(int userNumber);
	void getActiveAccounts();
	std::string getDirectoryFile() const override;
	std::string getRole() const override;
};

#endif