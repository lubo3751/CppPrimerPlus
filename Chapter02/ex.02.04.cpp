/* ex.02.04.cpp
Write a program that asks the user to enter his or her age. 
The program then should display the age in months:

Enter your age: 29
Your age in months is 384.
*/

#include <iostream>

// function prototype
int ageInMonths(int);

int main()
{
	using namespace std;
	
	cout << "Enter your age: ";
	int age;
	cin >> age;

	age = ageInMonths(age);
	cout << "Your age in months is " << age << endl;

	return 0;
}

int ageInMonths(int a)
{
	return a * 12;
}