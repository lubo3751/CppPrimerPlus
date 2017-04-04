/* ex.03.07.cpp
Write a program that asks you to enter an automobile gasoline 
consumption figure in the European style (liters per 100 kilometers) 
and converts to the U.S. style of miles per gallon. Note that in 
addition to using different units of measurement, the U.S. approach 
(distance / fuel) is the inverse of the European approach 
(fuel / distance). Note that 100 kilometers is 62.14 miles, 
and 1 gallon is 3.875 liters.Thus, 19 mpg is about 12.4 l/100 km, 
and 27 mpg is about 8.7 l/100 km.
*/

#include <iostream>

float const M_in_100km = 62.14;  // miles in 100 kilometers
float const L_in_g = 3.875;      // liters in a gallon

int main()
{  
	using namespace std;
	
	cout << "Enter automobile gasoline consumption in l/100km: ";
	double lPerKm;
	cin >> lPerKm;

	double mpg = M_in_100km / (lPerKm / L_in_g);	
	cout << "It's " << int(mpg) << " mpg." << endl;

    return 0; 
}