/* ex.06.03.cpp
Write a precursor to a menu-driven program.The program should display 
a menu offering four choices, each labeled with a letter. If the user 
responds with a letter other than one of the four valid choices, the 
program should prompt the user to enter a valid response until the 
user complies.Then the program should use a switch to select a simple 
action based on the user’s selection.A program run could look 
something like this:
Please enter one of the following choices:
c) carnivore p) pianist
t) tree g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree.
*/

#include <iostream>
using namespace std;

// function prototypes
void showmenu();
void carnivore();
void pianist();
void tree();
void game();

int main()
{
    showmenu();
    char choice;
    cin >> choice;
    while (choice != 'Q' && choice != 'q')
	{
		switch(choice)
		{
			case 'c':
			case 'C': carnivore();
				break;
			case 'p':
			case 'P': pianist();
				break;
			case 't':
			case 'T': tree();
				break;
			case 'g':
			case 'G': game();
				break;
		}
		showmenu();
		cin >> choice;
	}
    cout << "Bye!\n";
    return 0;
}

void showmenu()
{
    cout << "Please enter one of the following choices:\n"
			"c) carnivore		 p) pianist\n"
			"t) tree			 g) game\n"
			"q) quit\n";
}

void carnivore()
{
    cout << "A carnivore meaning 'meat eater' is an organism that \n"
			"derives its energy and nutrient requirements from a diet \n"
			"consisting mainly or exclusively of animal tissue, whether \n"
			"through predation or scavenging.\n";
}

void pianist()
{
    cout << "In this adaptation of the autobiography \"The Pianist: The \n"
			"Extraordinary True Story of One Man's Survival in Warsaw, \n"
			"1939-1945,\" Wladyslaw Szpilman (Adrien Brody), a Polish Jewish \n"
			"radio station pianist, sees Warsaw change gradually as World \n"
			"War II begins.\n";
}

void tree()
{
    cout << "In botany, a tree is a perennial plant with an elongated stem, \n"
			"or trunk, supporting branches and leaves in most species.\n";
}

void game()
{
    cout << "Game Digital plc is a British video games retail company. \n"
			"The company's origins lie in the founding of the Rhino Group \n"
			"by Terry Norris and Bev Ripley in 1991.\n";
}