/* ex.06.06.cpp
Put together a program that keeps track of monetary contributions to the Society
for the Preservation of Rightful Influence. It should ask the user to enter the number
of contributors and then solicit the user to enter the name and contribution of
each contributor.The information should be stored in a dynamically allocated array
of structures. Each structure should have two members: a character array (or else a
string object) to store the name and a double member to hold the amount of the
contribution.After reading all the data, the program should display the names and
amounts donated for all donors who contributed $10,000 or more.This list should
be headed by the label Grand Patrons.After that, the program should list the
remaining donors.That list should be headed Patrons. If there are no donors in one
of the categories, the program should print the word “none.”Aside from displaying
two categories, the program need do no sorting.
*/

#include <iostream>
#include <string>
using namespace std;

const int Limit = 10000;

struct donor {
	string name;
	double amount;
};

int main()
{
	// ask user how many donors
	cout << "The Society for the Preservation of Rightful Influence\n"
			"Enter the number of donors: ";
	int n_donors;
	(cin >> n_donors).get();
	
	//dynamically allocate array of structures
	donor *donors = new donor[n_donors];

	// initialize structure
	for (int i = 0; i < n_donors; ++i) 
	{
		cout << "Enter the name of the donor #" << i + 1 << ": ";
		getline(cin, donors[i].name);
		cout << "Enter their contribution: ";
		(cin >> donors[i].amount).get();
	}

	// display Grand Patrons
	cout << "Grand Patrons:\n";
	int counter = 0;
	for (int i = 0; i < n_donors; ++i) {
		if (donors[i].amount >= Limit) {
			cout << donors[i].name << " donated $" << donors[i].amount << endl;
			++counter;
		}
	}
	if (!counter)
		cout << "none\n";

	// display Patrons
	cout << "Patrons:\n";
	counter = 0;
	for (int i = 0; i < n_donors; ++i) {
		if (donors[i].amount < Limit) {
			cout << donors[i].name << endl;
			++counter;
		}
	}
	if (!counter)
		cout << "none\n";

    return 0;
}