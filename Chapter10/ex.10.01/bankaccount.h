// ex.10.01.bankaccount.h -- BankAccount class declaration

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <string>

class BankAccount
{
private:
    std::string name;
    std::string acctnum;
    double balance;
public:
    BankAccount(const std::string & client,
                const std::string & num, double bal = 0.0);
    void deposit(double cash);
    void withdraw(double cash);
    void show(void) const;
};

#endif