#include <iostream>
#include <string>
using namespace std;

const int LIMIT = 10000;

struct donor {
    string name;
    double amount;
};

int main()
{
    // ask user how many donors
    cout << "The Society for the Preservation of Rightful Influence" << endl;
    cout << "Enter the number of donors: ";
    int num_of_donors;
    (cin >> num_of_donors).get();

    //dynamically allocate array of structures
    donor * pt_donors = new donor[num_of_donors];

    // initialize structure
    for (int i = 0; i < num_of_donors; ++i) 
    {
        // solicit and set name
        cout << "Enter the name of the donor #" << i + 1 << ": ";
        getline(cin, pt_donors[i].name);
        while (pt_donors[i].name == "")
        {
            cout << "Error, nothing entered." << endl;
            cout << "Enter the name of the donor #" << i + 1 << ": ";
            getline(cin, pt_donors[i].name);
        }
        // solicit and set amount
        while (1)
        {
            cout << "Enter their contribution: $";
            cin >> pt_donors[i].amount;

            if (cin.fail())             // no extraction took place
            {
                cin.clear();            // clear error flags
                cin.ignore(1000, '\n'); // clear bad input from the stream
                cout << "Error. Invalid value entered." << endl;
                continue;               // try again
            }

            cin.ignore(1000, '\n'); // clear additional input from the stream
            if (cin.gcount() > 1)   // if more than one additional char cleared
            {                       // we'll consider this input to be invalid
                cout << "Error. Invalid value entered." << endl;
                continue;           // try again
            }

            if (pt_donors[i].amount <= 0) // make sure input is positive
            {
                cout << "Error. Negative value entered." << endl;
                continue;  // try again
            }
            break;
        }
    }    

    // display Grand Patrons
    cout << fixed << showpoint;
    cout.precision(2);
    cout << "Grand Patrons:" << endl;
    int counter = 0;
    for (int i = 0; i < num_of_donors; ++i) {
        if (pt_donors[i].amount >= LIMIT) {
            cout << pt_donors[i].name << " donated $" << pt_donors[i].amount << endl;
            ++counter;
        }
    }
    if (!counter) {
        cout << "none" << endl;
    }

    // display Patrons
    cout << "Patrons:" << endl;
    counter = 0;
    for (int i = 0; i < num_of_donors; ++i) {
        if (pt_donors[i].amount < LIMIT) {
            cout << pt_donors[i].name << endl;
            ++counter;
        }
    }
    if (!counter) {
        cout << "none" << endl;
    }

    return 0;
}
