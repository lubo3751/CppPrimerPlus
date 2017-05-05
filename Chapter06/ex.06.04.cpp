/* ex.06.04.cpp
When you join the Benevolent Order of Programmers, you can be known at BOP
meetings by your real name, your job title, or your secret BOP name.Write a program
that can list members by real name, by job title, by secret name, or by a member’s
preference. Base the program on the following structure:

// Benevolent Order of Programmers name structure
struct bop {
    char fullname[strsize]; // real name
    char title[strsize]; // job title
    char bopname[strsize]; // secret BOP name
    int preference; // 0 = fullname, 1 = title, 2 = bopname
};

In the program, create a small array of such structures and initialize it to suitable
values. Have the program run a loop that lets the user select from different alternatives:

a. display by name b. display by title
c. display by bopname d. display by preference
q. quit

Note that “display by preference” does not mean display the preference member; it
means display the member corresponding to the preference number. For instance, if
preference is 1, choice d would display the programmer’s job title.A sample run
may look something like the following:

Benevolent Order of Programmers Report
a. display by name b. display by title
c. display by bopname d. display by preference
q. quit
Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!
*/

#include <iostream>
using namespace std;

const int StrSIZE = 30;
const int ArSIZE = 5;

struct bop {          // Benevolent Order of Programmers name structure
    char fullname[StrSIZE]; // real name
    char title[StrSIZE];    // job title
    char bopname[StrSIZE];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

bop arBop[ArSIZE] = { // Array of bop structures
    {"John Smith", "Programmer", "josm", 2},
    {"Ann Black", "Software Architect", "anbl", 2},
    {"Jim Jones", "Senior Software Engineer", "jijo", 1},
    {"Peter Williams", "Coder", "pewil", 0},
    {"Brenda Taylor", "Software Developer", "braylor", 2}
};

// function prototypes
void showmenu();
void displayByName();
void dislplayByTitle();
void displayByBopname();
void displayByPreference();

int main() {
    showmenu();
    char choice;
    cin >> choice;

    while (choice != 'Q' && choice != 'q') {
        switch(choice) {
            case 'a':
            case 'A': displayByName();
                break;
            case 'b':
            case 'B': dislplayByTitle();
                break;
            case 'c':
            case 'C': displayByBopname();
                break;
            case 'd':
            case 'D': displayByPreference();
                break;
            default : cout << "That's not a choice." << endl;;
                showmenu();
                cin >> choice;
                continue;
        }
        cout << "Next choice: ";
        cin >> choice;
    }
    cout << "Bye!" << endl;
    return 0;
}

void showmenu() {
    cout << "Benevolent Order of Programmers Repor" << endl;
    cout << "a. display by name         b. display by title" << endl;
    cout << "c. display by bopname      d. display by preference" << endl;
    cout << "q. quit" << endl;
    cout << "Enter your Choice: ";
}

void displayByName() {
    for (int i = 0; i < ArSIZE; ++i) {
        cout << arBop[i].fullname << endl;
    }
}

void dislplayByTitle() {
    for (int i = 0; i < ArSIZE; ++i) {
        cout << arBop[i].title << endl;
    }
}

void displayByBopname() {
    for (int i = 0; i < ArSIZE; ++i) {
        cout << arBop[i].bopname << endl;
    }
}

void displayByPreference() {
    for (int i = 0; i < ArSIZE; ++i)  {
        switch (arBop[i].preference) {
            case 0: cout << arBop[i].fullname << endl;
                break;
            case 1: cout << arBop[i].title << endl;
                break;
            case 2: cout << arBop[i].bopname << endl;
                break;
        }
    }
}
