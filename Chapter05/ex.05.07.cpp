/* ex.05.07.cpp
Design a structure called car that holds the following infor-
mation about an automobile: its make, as a string in a character 
array or in a string object, and the year it was built, as an 
integer.Write a program that asks the user how many cars to 
catalog. The program should then use new to create a dynamic 
array of that many car structures. Next, it should prompt the 
user to input the make (which might consist of more than one 
word) and year information for each structure. Note that this 
requires some care because it alternates reading strings with 
numeric data (see Chapter 4). Finally, it should display the 
contents of each structure.A sample run should look something 
like the following:

How many cars do you wish to catalog? 2
Car #1:
Please enter the make: Hudson Hornet
Please enter the year made: 1952
Car #2:
Please enter the make: Kaiser
Please enter the year made: 1951
Here is your collection:
1952 Hudson Hornet
1951 Kaiser
*/

#include <iostream>
#include <string>

using namespace std;

struct car
{
	string make;
	int year;
};

int main()
{
	cout << "How many cars do you wish to catalog? ";
	int n_cars;
	(cin >> n_cars).get();

	car * cars = new car [n_cars];

	for (int i = 0; i < n_cars; ++i)
	{
		cout << "Car #" << i + 1 << ":\n"
			 << "Please enter the make: ";
		getline(cin, cars[i].make);
		cout << "Please enter the year made: ";
		(cin >> cars[i].year).get();
	}

	cout << "Here is your collection:" << endl;
	for (int i = 0; i < n_cars; ++i)
	{
		cout << cars[i].year << " " << cars[i].make << endl;
	}

    return 0;
}