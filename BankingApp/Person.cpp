#include "Person.h"

Person::Person(const std::string& n, const std::string& p, int an)
    : name(n), password(p), acctNum(an) {
}

Person::~Person() = default;

std::string Person::getName() const {
    return name;
}

std::string Person::getPass() const {
    return password;
}

int Person::getAcctNum() const {
    return acctNum;
}

void Person::setName(const std::string& n) {
    name = n;
}

void Person::setPass(const std::string& p) {
    password = p;
}

void Person::setAcctNum(int an) {
    acctNum = an;
}