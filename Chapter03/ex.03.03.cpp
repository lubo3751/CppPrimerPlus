/* ex.03.03.cpp
Write a program that asks the user to enter a latitude in degrees, 
minutes, and seconds and that then displays the latitude in decimal 
format.There are 60 seconds of arc to a minute and 60 minutes of 
arc to a degree; represent these values with symbolic constants. 
You should use a separate variable for each input value.A sample
run should look like this:

Enter a latitude in degrees, minutes, and seconds:
First, enter the degrees: 37
Next, enter the minutes of arc: 51
Finally, enter the seconds of arc: 19
37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
*/

#include <iostream>

float const SecInMin = 60.0;
float const MinInDeg = 60.0;

int main()
{  
	using namespace std;

	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First, enter the degrees: ";
	float deg;
	cin >> deg;
	cout << "Next, enter the minutes of arc: ";
	float min;
	cin >> min;
	cout << "Finally, enter the seconds of arc: ";
	float sec;
	cin >> sec;

	float flDeg = deg + ((min + (sec / SecInMin) ) / MinInDeg);

	cout << deg << " degrees, " << min << " minutes, "
		 << sec << " seconds = " << flDeg << " degrees" << endl; 

    return 0; 
}