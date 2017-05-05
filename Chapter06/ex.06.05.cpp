/* ex.06.05.cpp
The Kingdom of Neutronia, where the unit of currency is the tvarp, 
has the following income tax code:
First 5,000 tvarps: 0% tax
Next 10,000 tvarps: 10% tax
Next 20,000 tvarps: 15% tax
Tvarps after 35,000: 20% tax
For example, someone earning 38,000 tvarps would owe 5,000 × 0.00 + 
10,000 × 0.10 + 20,000 × 0.15 + 3,000 × 0.20, or 4,600 tvarps. Write 
a program that uses a loop to solicit incomes and to report tax owed.
The loop should terminate when the user enters a negative number or 
non-numeric input.
*/

#include <iostream>

const double Under15 = 10000.0 * 0.1;
const double Under35 = Under15 + 20000.0 * 0.15;
const double Over5 = 0.1;
const double Over15 = 0.15;
const double Over35 = 0.2;

// function prototype
double calcTax (double);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    double income;
    double tax;
    while (1)
    {
        income = -1;
        cout << "Please enter your income: ";
        cin >> income;
        cin.ignore(1000, '\n'); // clear rubbish input from the stream
        if (cin.gcount() > 1) { // if more than '\n' cleared
            break;              // non-numeric input i.e. 120abc, ..., abc etc.
        }
        if (income < 0) {      // negative or non-numeric input
            break;  
        }
        tax = calcTax(income);
        cout << "Your tax is " << tax << endl;
    }
    cout << "Bye." << endl;
    return 0;
}

double calcTax (double i)
{
    double tax = 0;
    if (i > 35000) {
        tax += (i - 35000) * Over35 + Under35;
    } else if (i > 15000) {
        tax += (i - 15000) * Over15 + Under15;
    } else if (i > 5000) {
        tax += (i - 5000) * Over5;
    }
    return tax;
}
