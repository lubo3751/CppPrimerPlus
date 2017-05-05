/* ex.07.08.a 
Redo Listing 7.15 without using the array class. Do two versions:
a. Use an ordinary array of const char * for the strings representing the season
names, and use an ordinary array of double for the expenses.
b. Use an ordinary array of const char * for the strings representing the season
names, and use a structure whose sole member is an ordinary array of
double for the expenses. (This design is similar to the basic design of the
array class.) 
*/

#include <iostream>
#include <string>

const int SEASONS = 4;
const char * Snames[SEASONS] = {"Spring", "Summer", "Fall", "Winter"};

// function prototypes
void fill(double pa[SEASONS]);
void show(double da[SEASONS]);

int main()
{
    double expenses[SEASONS];
    fill(expenses);
    show(expenses);
    return 0;
}

void fill(double pa[SEASONS])
{
    for (int i = 0; i < SEASONS; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa[i];
    }
}

void show(double da[SEASONS])
{
    double total = 0.0;
    std::cout << std::endl << "EXPENSES" << std::endl;
    for (int i = 0; i < SEASONS; i++)
    {
        std::cout << Snames[i] << ": $" << da[i] << std::endl;
        total += da[i];
    }
    std::cout << "Total: $" << total << std::endl;
}
