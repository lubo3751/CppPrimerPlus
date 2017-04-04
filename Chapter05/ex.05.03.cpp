/* ex.05.03.cpp
Write a program that asks the user to type in numbers.After 
each entry, the program should report the cumulative sum of 
the entries to date.The program should terminate when the user 
enters 0.
*/

#include <iostream>

int main()
{
	using namespace std;
	
	cout << "Enter a number (0 to quit) : ";
	double number, sum = 0;
	cin >> number;

	while (number)
	{
		sum += number;
		cout << "The cumulative sum is " << sum << endl;
		cout << "Enter a number (o to quit) : ";
		cin >> number;
	}

    return 0;
}