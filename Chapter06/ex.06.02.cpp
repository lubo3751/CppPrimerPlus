/* ex.06.02.cpp
Write a program that reads up to 10 donation values into an array of 
double. (Or, if you prefer, use an array template object.) The program 
should terminate input on non-numeric input. It should report the 
average of the numbers and also report how many numbers in the array 
are larger than the average.
*/

#include <iostream>
#include <array>

const int MAX = 10;

int main()
{
    using namespace std;
    // get data
    array<double, MAX> donations;
    cout << "Please enter the values of donations." << endl;
    cout << "You may enter up to " << MAX;
    cout << " values <non-numeric input to terminate>." << endl;
    cout << "Donation #1: ";
    int i = 0;
    while (i < MAX && cin >> donations[i]) {
        if (++i < MAX) {
            cout << "donation #" << i+1 << ": ";
        }
    }
    // calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++) {
        total += donations[j];
    }
    double average = total / i;
    // calculate number of values above average
    int aboves = 0;
    for (int j = 0; j < i; j++) {
        if (donations[j] > average) {
            ++aboves;
        }
    }
    // report results
    if (i == 0) {
        cout << "No donations" << endl;
    } else {
        cout << average << " = average value of " << i << " donations" << endl;
        if (aboves == 1) {
            cout << aboves << " value was above the average" << endl;
        } else {	
            cout << aboves << " values were above the average" << endl;
        }
    }
    cout << "Done." << endl;
    return 0; 
}
