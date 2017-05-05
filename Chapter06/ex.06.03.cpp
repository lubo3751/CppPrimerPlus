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
    cout << "Bye!" << endl;
    return 0;
}

void showmenu()
{
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore		 p) pianist" << endl;
    cout << "t) tree			 g) game" << endl;
    cout << "q) quit" << endl;
}

void carnivore()
{
    cout << "A carnivore meaning 'meat eater' is an organism that " << endl;
    cout << "derives its energy and nutrient requirements from a diet " << endl;
    cout << "consisting mainly or exclusively of animal tissue, whether " << endl;
    cout << "through predation or scavenging." << endl;
}

void pianist()
{
    cout << "In this adaptation of the autobiography \"The Pianist: The " << endl;
    cout << "Extraordinary True Story of One Man's Survival in Warsaw, " << endl;
    cout << "1939-1945,\" Wladyslaw Szpilman (Adrien Brody), a Polish Jewish " << endl;
    cout << "radio station pianist, sees Warsaw change gradually as World " << endl;
    cout << "War II begins." << endl;
}

void tree()
{
    cout << "In botany, a tree is a perennial plant with an elongated stem, " << endl;
    cout << "or trunk, supporting branches and leaves in most species." << endl;
}

void game()
{
    cout << "Game Digital plc is a British video games retail company. " << endl;
    cout << "The company's origins lie in the founding of the Rhino Group " << endl;
    cout << "by Terry Norris and Bev Ripley in 1991." << endl;
}
