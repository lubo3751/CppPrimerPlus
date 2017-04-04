/* ex.05.06.cpp
Do Programming Exercise 5 but use a two-dimensional array to 
store input for 3 years of monthly sales. Report the total 
sales for each individual year and for the
combined years.
*/

#include <iostream>
#include <string>
#include <array>

const int Months = 12;
const int Years = 3;

int main()
{
	using namespace std;

	array<string, Months> months = 
		{"January", "February", "March", "April", "May", 
		 "June", "July", "August", "September", "October", 
		 "November", "December"};
	array<array<int,Months>, Years> sales;

	for (int year = 0; year < Years; ++year)
	{
		for (int month = 0; month < Months; ++month)
		{
			cout << "Enter sales for " << months[month] 
			     << " year " << year + 1 << ": ";
			cin >> sales[year][month];
		}
	}

	int total, grandTotal = 0;
	for (int year = 0; year < Years; ++year)
	{
		total = 0;
		for (int month = 0; month < Months; ++month)
		{
			total += sales[year][month];
		}
		cout << "Total sales for year " << year + 1 
			 << ": " << total << endl;
		grandTotal += total;
	}

	cout << "Total sales for all three years: " << grandTotal << endl;

    return 0;
}