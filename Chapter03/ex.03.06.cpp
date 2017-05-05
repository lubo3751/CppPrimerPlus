/* ex.03.06.cpp
Write a program that asks how many miles you have driven and 
how many gallons of gasoline you have used and then reports the 
miles per gallon your car has gotten. Or, if you prefer, the 
program can request distance in kilometers and petrol in liters
and then report the result European style, in liters per 100 
kilometers.
*/

#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter how many miles you have driven: ";
    double miles;
    cin >> miles;
    cout << "Enter how many gallons of gasoline your car has used: ";
    double gallons;
    cin >> gallons;

    double mpg = miles / gallons;
    cout << "Your car drives " << mpg << " miles per gallon." << endl;

    return 0; 
}
