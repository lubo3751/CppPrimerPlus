/* ex.05.05.cpp
You sell the book C++ for Fools.Write a program that has you 
enter a year’s worth of monthly sales (in terms of number of 
books, not of money).The program should use a loop to prompt 
you by month, using an array of char * (or an array of string 
objects, if you prefer) initialized to the month strings and 
storing the input data in an array of int.Then, the program 
should find the sum of the array contents and report the total 
sales for the year.
*/

#include <iostream>
#include <string>

const int Months = 12;

int main()
{
	using namespace std;
		
	string months[Months] = 
		{"January", "February", "March", "April", "May", 
		 "June", "July", "August", "September", "October", 
		 "November", "December"};
	int sales[Months];
	for (int i = 0; i < Months; ++i)
	{
		cout << "Enter the sales for " << months[i] << ": ";
		cin >> sales[i];
	}

	int sum = 0;
	for (int i = 0; i < Months; ++i)
	{
		sum += sales[i];
	}

	cout << "The total sales for the year is " << sum << endl;

    return 0;
}