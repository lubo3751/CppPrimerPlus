/* ex.05.06.cpp
Do Programming Exercise 5 but use a two-dimensional array to 
store input for 3 years of monthly sales. Report the total 
sales for each individual year and for the
combined years.
*/

#include <iostream>
#include <string>
#include <array>

const int MONTHS = 12;
const int YEARS = 3;

int main()
{
    using std::array;
    using std::string;
    using std::cout;
    using std::cin;
    using std::endl;
	
    array<string, MONTHS> ar_months = 
        {"January", "February", "March", "April", "May", "June", 
         "July", "August", "September", "October", "November", "December"};
    array<array<int,MONTHS>, YEARS> ar_sales;

    for (int year = 0; year < YEARS; ++year)
    {
        for (int month = 0; month < MONTHS; ++month)
        {
            cout << "Enter sales for " << ar_months[month];
            cout << " year " << year + 1 << ": ";
            cin >> ar_sales[year][month];
        }
    }

    int total, grand_total = 0;
    for (int year = 0; year < YEARS; ++year)
    {
        total = 0;
        for (int month = 0; month < MONTHS; ++month) {
            total += ar_sales[year][month];
        }
        cout << "Total sales for year " << year + 1 << ": " << total << endl;
        grand_total += total;
    }

    cout << "Total sales for all three years: " << grand_total << endl;

    return 0;
}
