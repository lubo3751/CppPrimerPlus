// ex.10.04.namesp.cpp -- namespaces
#include <iostream>
#include "namesp.h"

namespace SALES
{
    Sales::Sales(){}

    Sales::Sales(const double ar[], int n)
    {			
        n = n < QRTRS ? n : QRTRS;    // avoid buffer overflow
        max = min = ar[0];
        // set *this members to 0
        average = 0;
        for (int i = 0; i < QRTRS; i++) {
            sales[i] = 0;
        }

        // set *this members to new values
        for (int i = 0; i < n; i++) 
        {
            sales[i] = ar[i];
            max = (max > ar[i]) ? max : ar[i];
            min = (min < ar[i]) ? min : ar[i];
            average += ar[i];
        }
        average /= n;
    }

    void Sales::setSales()
    {
        using std::cout;
        using std::cin;
        using std::endl;
        // solicit sales from user
        double sls[QRTRS];
        cout << "Enter sales for each quarter" << endl << endl;
        for (int i = 0; i < QRTRS; i++)
        {
            while (1)
            {
                cout << "Q" << i+1 << ": $";
                cin >> sls[i];

                if (cin.fail())             // no extraction took place
                {
                    cin.clear();            // clear error flags
                    cin.ignore(1000, '\n'); // clear bad input from the stream
                    cout << "Error. Invalid value entered." << endl;
                    cout << "Try again" << endl;
                    continue;               // try again
                }

                cin.ignore(1000, '\n'); // clear additional input from the stream
                if (cin.gcount() > 1)   // if more than one additional char cleared
                {                       // we'll consider this input to be invalid
                    cout << "Error. Invalid value entered." << endl;
                    cout << "Try again" << endl;
                    continue;           // try again
                }

                if (sls[i] <= 0) // make sure input is positive
                {
                    cout << "Error. Negative value entered." << endl;
                    cout << "Try again" << endl;
                    continue;        // try again
                }
                break;
            }
        }
        // set *this members to solicited values
        *this = Sales(sls, QRTRS);
        cout << endl;
    }

    void Sales::showSales() const
    {
        using std::cout;
        using std::endl;
        using std::ios_base;
        // set format to #.##
        ios_base::fmtflags orig = 
            cout.setf(ios_base::fixed, ios_base::floatfield); 
        std::streamsize prec = cout.precision(2);
	
        for (int i = 0; i < QRTRS; i++){
            cout << endl << "Q" << i+1 << ": $" << sales[i];
        }
        cout << endl << "average: $" << average << endl;
        cout << "max: $" << max << endl;
        cout << "min: $" << min << endl << endl;

        // restore original format
        cout.setf(orig, ios_base::floatfield);
        cout.precision(prec);
    }
}
