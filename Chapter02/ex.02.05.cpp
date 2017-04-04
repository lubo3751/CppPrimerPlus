/* ex.02.05.cpp
Write a program that has main() call a user-defined function 
that takes a Celsius temperature value as an argument and then 
returns the equivalent Fahrenheit value. The program should 
request the Celsius value as input from the user and display
the result, as shown in the following code:

Please enter a Celsius value: 20
20 degrees Celsius is 68 degrees Fahrenheit.

For reference, here is the formula for making the conversion:
Fahrenheit = 1.8 × degrees Celsius + 32.0
*/

#include <iostream>

// function prototype
double toFahr(double);

int main()
{
	using namespace std;
	
	cout << "Please enter a Celsius value: ";
	double cels;
	cin >> cels;

	double fahr;
	fahr = toFahr(cels);
	cout << cels << " degrees Celsius is "
		 << fahr << " degrees Fahrenheit." << endl;

	return 0;
}

double toFahr(double ce)
{
	return 1.8 * ce + 32.0;
}