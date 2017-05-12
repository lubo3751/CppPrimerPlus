// ex.10.08.list.cpp -- List class implementation
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "list.h"
List::List()  // create an empty list
{
    last = 0;
}

bool List::isempty() const
{
    return last == 0;
}

bool List::isfull() const
{
    return last == MAX;
}

bool List::add(const Item & item)
{
    if (last < MAX)
    {
        items[last++] = item;
        return true;
    }
    else
        return false;
}

void List::visit(void (*pf)(Item &))
{
    for (int i = 0; i < last; i++)
        (*pf)(items[i]);
}

void show_menu()
{
    std::cout << "Savings Accounts Simulator\n"
        "a. new account        b. add interests\n"
        "c. show accounts      q. quit\n";
}

void solicit_choice(char * choice)
{
    using std::cout;
    using std::cin;
    while (1)
    {
        cout << "Enter you choice: ";
        cin >> *choice;

        if (cin.fail())             // no extraction took place
        {
            cin.clear();            // clear error flags
            cin.ignore(1000, '\n'); // cler stream
            cout << "Error. Invalid value entered.\n";
            continue;               // try again
        }

        cin.ignore(1000, '\n'); // clear stream
        if (cin.gcount() > 1)   // more than one char cleared
        {
            cout << "Error. Invalid value entered.\n";
            continue;           // try again
        }

        if (toupper(*choice) != 'A' && toupper(*choice) != 'B' 
            && toupper(*choice) != 'C' && toupper(*choice) != 'Q') 
        {
            cout << "Error. Invalid value entered.\n";
            continue;  // try again
        }
        cout << std::endl;
        break;         // input ok
    }
}

void add_interest(Item & it)
{
    it.deposit *= (1 + (it.interest / 100.0));
}

void show_account(Item & it)
{
    using std::cout;
    using std::endl;
    using std::ios_base;
    // set format to #.##
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield); 
    std::streamsize prec = cout.precision(2);
    
    cout << std::setw(15) << std::left << it.name; 
    cout << "  $" << it.deposit << endl;

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

Account & solicit_info(Account & ac)
{
    using std::cout;
    using std::cin;
    // solicit account name
    cout << "Enter account name: ";
    getline(cin, ac.name);
    while (ac.name == "")
    {
        cout << "Error. Nothing entered.\n"
             << "Please enter account name: ";
        getline (cin, ac.name);
    }
    // solicit deposit value
    while (1)
    {
        cout << "Enter deposit value ($10 to &10000): $";
        cin >> ac.deposit;
        if (cin.fail())             // no extraction took place
        {
            cin.clear();            // clear error flags
            cin.ignore(1000, '\n'); // cler stream
            cout << "Error. Invalid value entered.\n";
            continue;               // try again
        }
        cin.ignore(1000, '\n'); // clear stream
        if (cin.gcount() > 1)   // more than one char cleared
        {
            cout << "Error. Invalid value entered.\n";
            continue;           // try again
        }
        if (ac.deposit < 10.0)  // input less than 10
        {
            cout << "Error. Invalid value entered.\n";
            continue;           // try again
        }
        if (ac.deposit > 10000.0) // input more than 10000
        {
            cout << "Error. Invalid value entered.\n";
            continue;             // try again
        }
        break;         // input ok
    }
    // solicit interest rate
    while (1)
    {
        cout << "Enter interest rate (0.1 to 10): ";
        cin >> ac.interest;
        if (cin.fail())             // no extraction took place
        {
            cin.clear();            // clear error flags
            cin.ignore(1000, '\n'); // cler stream
            cout << "Error. Invalid value entered.\n";
            continue;               // try again
        }
        cin.ignore(1000, '\n'); // clear stream
        if (cin.gcount() > 1)   // more than one char cleared
        {
            cout << "Error. Invalid value entered.\n";
            continue;           // try again
        }
        if (ac.interest <= 0) // negative input
        {
            cout << "Error. Invalid value entered.\n";
            continue;         // try again
        }
        if (ac.interest > 10.0) // input more than 10
        {
            cout << "Error. Invalid value entered.\n";
            continue;           // try again
        }
        break;         // input ok
    }
    cout << std::endl;
    return ac;
}

