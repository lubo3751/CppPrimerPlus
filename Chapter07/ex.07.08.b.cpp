/* ex.07.08.b 
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

struct costs
{
    double expenses[SEASONS];
};

// function prototypes
void fill(costs *paid);
void show(costs paid);

int main()
{
    costs paid;
    fill(&paid);
    show(paid);
    return 0;
}

void fill(costs *paid)
{
    for (int i = 0; i < SEASONS; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> paid->expenses[i];
    }
}

void show(costs paid)
{
    double total = 0.0;
    std::cout << std::endl << "EXPENSES" << std::endl;
    for (int i = 0; i < SEASONS; i++)
    {
        std::cout << Snames[i] << ": $" << paid.expenses[i] << std::endl;
        total += paid.expenses[i];
    }
    std::cout << "Total: $" << total << std::endl;
}
