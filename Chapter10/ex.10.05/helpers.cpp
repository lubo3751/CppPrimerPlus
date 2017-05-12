// ex.10.05.helpers.cpp -- implementation of helpers functions
#include <iostream>
#include "helpers.h"

char * get_name()
{
    using std::cout;
    using std::cin;
    static char name[LEN];
    cout << "Enter a customer full name: ";
    cin.get(name, LEN);
    while (strlen(name) == 0)
    {
        cin.clear();
	    cin.get();
	    cout << "Error, nothing entered.\n"
	         << "Enter a customer full name: ";
        cin.get(name, LEN);
    }
    return name;
}

double get_payment()
{
    using std::cout;
    using std::cin;
    double payment;
    while (1)
    {
        cout << "Enter a payment value: $";
        cin >> payment;

        if (cin.fail())             // no extraction took place
        {
            cin.clear();            // clear error flags
            cin.ignore(1000, '\n'); // cler stream
            cout << "Error. Invalid value entered.\n";
            continue;               // try again
        }

        cin.ignore(1000, '\n'); // clear stream
        if (cin.gcount() > 1)   // if more than one char cleared
        {                       // input is invalid
            cout << "Error. Invalid value entered.\n";
            continue;           // try again
        }

        if (payment <= 0) // make sure input is positive
        {
            cout << "Error. Negative value entered.\n";
            continue;  // try again
        }
        break;         // input ok
    }
    cout << std::endl;
    return payment;
}