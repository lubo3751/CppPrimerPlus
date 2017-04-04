/* ex.04.02.cpp
Rewrite Listing 4.4, using the C++ string class instead of char 
arrays.
*/

#include <iostream>
#include <string>

int main()
{
    using namespace std;

	cout << "Enter your name:" << endl;
    string name;
	getline(cin, name);
    
	cout << "Enter your favorite dessert:" << endl;
    string dessert;
	getline(cin, dessert);
   
	cout << "I have some delicious " << dessert
		 << " for you, " << name << "." << endl;

    return 0; 
}