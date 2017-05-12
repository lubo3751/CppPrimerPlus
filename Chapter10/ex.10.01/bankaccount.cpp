// ex.10.01.bankaccount.cpp -- BankAccount class implementation

#include <iostream>
#include "bankaccount.h"

BankAccount::BankAccount(const std::string & client,
                         const std::string & num, double bal)
{
    name = client;
    acctnum = num;
    balance = bal;
}

void BankAccount::deposit(double cash)
{
    balance += cash;
}

void BankAccount::withdraw(double cash)
{
    balance -= cash;
}

void BankAccount::show(void) const
{
    using std::cout;
    using std::endl;
    using std::ios_base;

    // set format to #.##
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield); 
    std::streamsize prec = cout.precision(2);

    cout << "Client Name: " << name;
    cout << "  Account Number: " << acctnum << endl;
    cout << "  Balance: $" << balance << endl << endl;

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}