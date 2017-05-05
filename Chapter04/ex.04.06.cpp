/* ex.04.06.cpp
The CandyBar structure contains three members, as described in 
Programming Exercise 5.Write a program that creates an array of 
three CandyBar structures, initializes them to values of your 
choice, and then displays the contents of each structure.
*/

#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    int calories;
};

int main()
{
    using std::cout;
    using std::endl;

    CandyBar candies[3] =
    {
        {"KitKat", 4.5, 280},
        {"Mars", 5.5, 250},
        {"Bounty", 6.5, 300}
    };

    cout << candies[0].brand << ", ";
    cout << candies[0].weight << ", ";
    cout << candies[0].calories << endl;

    cout << candies[1].brand << ", ";
    cout << candies[1].weight << ", ";
    cout << candies[1].calories << endl;

    cout << candies[2].brand << ", ";
    cout << candies[2].weight << ", ";
    cout << candies[2].calories << endl;

    return 0; 
}
