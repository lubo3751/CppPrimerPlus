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

const int H_IN_D = 24;  // hours in a day
const int M_IN_H = 60;  // minutes in an hour 
const int S_IN_M = 60;  // seconds in a minute

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
		
    cout << "Enter the number of seconds: ";
    long long secs_total;
    cin >> secs_total;

    int secs = secs_total % S_IN_M;
    int mins = secs_total % (S_IN_M * M_IN_H) / M_IN_H;
    int hours = secs_total % (S_IN_M * M_IN_H * H_IN_D) / S_IN_M / M_IN_H;
    int days = secs_total / (S_IN_M * M_IN_H * H_IN_D);

    cout << secs_total << " seconds = " << days << " days, ";
    cout << hours << " hours, " << mins << " minutes, ";
    cout << secs << " seconds" << endl; 

    return 0; 
}
