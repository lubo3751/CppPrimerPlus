// ex.10.03.main.cpp -- using the Golf class
// compile with golf.cpp
#include <iostream>
#include "golf.h"

int main(void)
{
    using std:: cout;
    using std:: endl;
    Golf players[MAX];
    int counter = 0;  // count entered players
    // prompt user input and set players
    cout << "Enter names and handicaps of golf players." << endl;
    cout << "You may enter up to " << MAX 
         << " records (empty name stops)." << endl;
    for (int i = 0; i < MAX; ++i) {
        cout << i+1 << "." << endl;
        if (!(players[i].setgolf())) {
            break;
        }
        ++counter;
    }
    // show players
    cout << endl;
    for (int i = 0; i < counter; ++i) {
        cout << "golf player " << i+1 << " ";
        players[i].showgolf();
    }
    // alter players
    players[0].reset_handicap(33);
    players[1].reset_handicap(21);
    // show players
    cout << endl;
    for (int i = 0; i < counter; ++i) {
        cout << "golf player " << i+1 << " ";
        players[i].showgolf();
    }
    cout << endl;
    return 0;
}