/* ex.04.09.cpp
Do Programming Exercise 6, but instead of declaring an array 
of three CandyBar structures, use new to allocate the array 
dynamically.
*/

#include<iostream>
#include<cstring>

struct CandyBar
{
    char brand[20];
    double weight;
    int calories;
};

int main(void)
{
    using std::cout;
    using std::endl;

    CandyBar * pt_CandyBar = new CandyBar [3];

    strcpy(pt_CandyBar[0].brand, "KitKat");
    pt_CandyBar[0].weight = 4.5;
    pt_CandyBar[0].calories = 280;

    strcpy(pt_CandyBar[1].brand, "Mars");
    pt_CandyBar[1].weight = 5.5;
    pt_CandyBar[1].calories = 250;

    strcpy(pt_CandyBar[2].brand, "Bounty");
    pt_CandyBar[2].weight = 6.5;
    pt_CandyBar[2].calories = 300;

    cout << pt_CandyBar[0].brand << ", ";
    cout << pt_CandyBar[0].weight << ", ";
    cout << pt_CandyBar[0].calories << endl;

    cout << pt_CandyBar[1].brand << ", ";
    cout << pt_CandyBar[1].weight << ", ";
    cout << pt_CandyBar[1].calories << endl;

    cout << pt_CandyBar[2].brand << ", ";
    cout << pt_CandyBar[2].weight << ", ";
    cout << pt_CandyBar[2].calories << endl;

    delete [] pt_CandyBar;

    return 0;
}
