/* ex.02.02.cpp
Write a C++ program that asks for a distance in furlongs and converts it to yards.
(One furlong is 220 yards.)
*/

#include <iostream>

// function prototype
int furToYar(int);

int main()
{
    using namespace std;
    
	int fur;
    cout << "Enter the distance in furlongs: ";
    cin >> fur;
    
	int yar = furToYar(fur);
    cout << fur << " furlongs = " << yar << " yards." << endl;

    return 0;
}

int furToYar(int fu)
{
     return fu * 220;
}