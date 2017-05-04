// golf.cpp -- function definitions

#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	using std::cout;
	using std::cin;
	using std::endl;

	// solicit and set fullname
    cout << "Enter a fullname: ";
	cin.getline(g.fullname, LEN);
	if (g.fullname[0] == '\0') {  // stop imput
		return 0;
	}

    // solicit and set handicap
	while (1)
	{
		cout << "Enter a handicap: ";
		cin >> g.handicap;
		if (cin.fail())             // no extraction took place
		{
			cin.clear();            // clear error flags
			cin.ignore(1000, '\n'); // clear bad input from the stream
			cout << "Error. Not an integer." << endl;
			continue;               // try again
		}
		cin.ignore(1000, '\n'); // clear out any additional input from the stream
		if (cin.gcount() > 1)   // if more than one additional char cleared
		{                       // we'll consider this input to be invalid
			cout << "Error. Not an integer." << endl;
			continue;           // try again
		}
		if (g.handicap <= 0) // make sure input is positive
		{	
			cout << "Error. Not a positive integer." << endl;
			continue;        // try again
		}
		break;
	}
	return 1;   // successful input
}

// reset handicap
void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	std::cout << "fullname, handicap: " << g.fullname 
        << ", " << g.handicap << std::endl;
}