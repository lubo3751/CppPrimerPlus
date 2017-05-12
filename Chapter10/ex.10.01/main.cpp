// ex.10.01.main.cpp - using the BankAccount class
// compile with bankaccount.cpp

#include <iostream>
#include "bankaccount.h"

int main()
{
    BankAccount account("John Smith", "2490096501");
    account.show();

    account.deposit(1200);
    account.show();

    account.withdraw(450);
    account.show();

    std::cout << "Bye" << std::endl << std::endl;
    return 0;
}
