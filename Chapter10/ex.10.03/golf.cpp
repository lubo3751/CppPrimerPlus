// ex.10.03.golf.cpp -- Golf class implementation
#include <iostream>
#include "golf.h"

Golf::Golf(char * name, int hc)
{
    strcpy_s(fullname, 40, name);
    handicap = hc;
}

int Golf::setgolf()
{
    using std::cout;
    using std::cin;
    using std::endl;
    // solicit fullname
    cout << "Enter a fullname: ";
    char fn[LEN] = "";
    cin.getline(fn, LEN);
    if (fn[0] == '\0') {  // stop imput
        return 0;
    }
    // solicit handicap
    int hc;
    while (1)
    {
        cout << "Enter a handicap: ";
        cin >> hc;
        if (cin.fail())             // no extraction took place
        {
            cin.clear();            // clear error flags
            cin.ignore(1000, '\n'); // clear stream
            cout << "Error. Not an integer." << endl;
            continue;               // try again
        }
        cin.ignore(1000, '\n'); // clear stream
        if (cin.gcount() > 1)   // if more than one char cleared
        {                       // input is invalid
            cout << "Error. Not an integer." << endl;
            continue;           // try again
        }
        if (hc <= 0)  // negative input
        {
            cout << "Error. Not a positive integer." << endl;
            continue; // try again
        }
        break;        // successful input
    }
    // set object members to entered values
    *this = Golf(fn, hc);
    return 1;
}

void Golf::reset_handicap(int hc)
{
    handicap = hc;
}

void Golf::showgolf()
{
    std::cout << fullname << ", " << handicap << std::endl;
}
