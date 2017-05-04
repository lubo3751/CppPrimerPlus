// ex.09.01

#include <iostream>
#include "golf.h"

const int MAX = 5;

int main(void)
{
	using std:: cout;
	using std:: endl;
	golf players[MAX];
	int counter = 0;  // count entered players
	
	// prompt user input and set players
	cout << "Enter names and handicaps of golf players." << endl;
	cout << "You may enter up to " << MAX 
		 << " records (empty name stops)." << endl;
	for (int i = 0; i < MAX; ++i) {
		cout << i+1 << "." << endl;
		if (!(setgolf(players[i]))) {
			break;
		}
		++counter;
	}
	
	// show players
	cout << endl;
	for (int i = 0; i < counter; ++i) {
		cout << "golf player " << i+1 << " ";
        showgolf(players[i]);
	}
	
	// alter players
	setgolf(players[0], "Jan Novak", 26);
	handicap(players[1], 21);
	
	// show players
	cout << endl;
	for (int i = 0; i < counter; ++i) {
		cout << "golf player " << i+1 << " ";
        showgolf(players[i]);
	}

	return 0;
}