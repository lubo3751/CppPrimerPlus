/* ex.07.05 
Define a recursive function that takes an integer argument and returns the factorial
of that argument. Recall that 3 factorial, written 3!, equals 3 × 2!, and so on, with 0!
defined as 1. In general, if n is greater than zero, n! = n * (n - 1)!.Test your function
in a program that uses a loop to allow the user to enter various values for which the
program reports the factorial. 
*/

#include <iostream>

long double factorial(int);

int main()
{
    using namespace std;
    cout << "Enter a positive integer: ";
    int number;
    while (cin >> number && number >= 0)
    {
        cout << number << "! = " << factorial(number) << endl;
        cout << "Enter another positive integer <q to quit>: ";
    }
    cout << "Bye" << endl;
    return 0;
}

long double factorial (int n)
{
    if ( n == 0 ) {
        return 1.0;
    } else {
        return n * factorial (n - 1);
    }
}
