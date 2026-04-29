#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "Person.h"

class Manager : public Person {

protected:

	static int userAmt;

public:

	Manager(const std::string&, const std::string& p, int an);

	void deleteUser(int userNumber);
	static int getActiveAccounts();
	static void updateActiveUsers();
	std::string getDirectoryFile() const override;
	std::string getRole() const override;
};

#endif