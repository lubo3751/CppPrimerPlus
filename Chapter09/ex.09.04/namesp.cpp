// ex.09.04.namesp.cpp -- namespaces

#include <iostream>
#include "namesp.h"

namespace SALES
{
	void setSales(Sales & s, const double ar[], int n)
	{
		n = n < QUARTERS ? n : QUARTERS;    // avoid buffer overflow
		
        // set all members of s to 0
        s.max = s.min = ar[0];
		s.average = 0;
		for (int i = 0; i < QUARTERS; i++){
			s.sales[i] = 0;
		}
		
        // set all members of s to new values
        for (int i = 0; i < n; i++) 
		{
			s.sales[i] = ar[i];
			s.max = (s.max > ar[i]) ? s.max : ar[i];
			s.min = (s.min < ar[i]) ? s.min : ar[i];
			s.average += ar[i];
		}
		s.average /= n;
	}

	void setSales(Sales & s)
	{
		using std::cout;
		using std::cin;
        using std::endl;
		
        // solicit and set elements of sales of s
        cout << "Enter sales for each quarter" << endl << endl;
		for (int i = 0; i < QUARTERS; i++)
		{
            while (1)
            {
                cout << "Q" << i+1 << ": $";
                cin >> s.sales[i];

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

                if (s.sales[i] <= 0) // make sure input is positive
                {
                    cout << "Error. Negative value entered." << endl;
                    cout << "Try again" << endl;
                    continue;        // try again
                }
                break;
            }
		}
        cout << endl;

		// set max, mix, and average of s
        s.max = s.min = s.sales[0];
		s.average = 0;
		for (int i = 0; i < QUARTERS; i++)
		{
			s.max = (s.max > s.sales[i]) ? s.max : s.sales[i];
			s.min = (s.min < s.sales[i]) ? s.min : s.sales[i];
			s.average += s.sales[i];
		}
		s.average /= QUARTERS;
	}

	void showSales(const Sales & s)
	{
		using std::cout;
		using std::endl;
        cout << std::fixed << std::showpoint;
        cout.precision(2);
		
        for (int i = 0; i < QUARTERS; i++){
			cout << endl << "Q" << i+1 << ": $" << s.sales[i];
		}
		cout << endl << "average: $" << s.average << endl;
		cout << "max: $" << s.max << endl;
		cout << "min: $" << s.min << endl << endl;
	}
}
