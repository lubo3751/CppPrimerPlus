/* ex.03.04.cpp
Write a program that asks the user to enter the number of seconds 
as an integer value (use type long, or, if available, long long) 
and that then displays the equivalent time in days, hours, minutes, 
and seconds. Use symbolic constants to represent the number of 
hours in the day, the number of minutes in an hour, and the number
of seconds in a minute.The output should look like this:

Enter the number of seconds: 31600000
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
*/

#include <iostream>

int const H_in_d = 24;  // hours in a day
int const M_in_h = 60;  // minutes in an hour 
int const S_in_m = 60;  // seconds in a minute

int main()
{  
	using namespace std;
			
	cout << "Enter the number of seconds: ";
	long long sAll;
	cin >> sAll;

	int s = sAll % S_in_m;                                        // seconds
	int m = sAll % (S_in_m * M_in_h) / M_in_h;                    // minutes
	int h = sAll % (S_in_m * M_in_h * H_in_d) / S_in_m / M_in_h;  // hours
	int d = sAll / (S_in_m * M_in_h * H_in_d);                    // days

	cout << sAll << " seconds = " << d << " days, "
		 << h << " hours, " << m << " minutes, " 
		 << s << " seconds" << endl; 

    return 0; 
}