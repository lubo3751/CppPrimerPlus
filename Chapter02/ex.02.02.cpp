/* ex.02.02.cpp
Write a C++ program that asks for a distance in furlongs and converts it to yards.
(One furlong is 220 yards.)
*/

#include <iostream>

// function prototype
int furlongs_to_yards(int);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    int furlongs;
    cout << "Enter the distance in furlongs: ";
    cin >> furlongs;

    int yards = furlongs_to_yards(furlongs);
    cout << furlongs << " furlongs = " << yards << " yards." << endl;

    return 0;
}

int furlongs_to_yards(int f)
{
     return f * 220;
}
