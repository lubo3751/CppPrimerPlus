/* ex.06.09.cpp
Do Programming Exercise 6 but modify it to get information from a file.The first
item in the file should be the number of contributors, and the rest of the file should
consist of pairs of lines, with the first line of each pair being a contributor’s name
and the second line being a contribution.That is, the file should look like this:
4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000
*/

#include <iostream>
#include <string>
#include <fstream>          // file I/O support
#include <cstdlib>          // support for exit()
using namespace std;

const int Limit = 10000;

struct donor {
	string name;
	double amount;
};

int main()
{
	char filename[] = "donors.txt";
    ifstream inFile;        // object for handling file input
	inFile.open(filename);  // associate inFile with a file

    if (!inFile.is_open())  // check the file has opened
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

	int n_donors;
	(inFile >> n_donors).get();  // read how many donors
	
	// dynamically allocate array of structures
	donor *donors = new donor[n_donors];

	// initialize structure
	for (int i = 0; i < n_donors; ++i) 
	{
		getline(inFile, donors[i].name);    // reads donor's name
		(inFile >> donors[i].amount).get(); // reads donor's contribution
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