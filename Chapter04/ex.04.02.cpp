/* ex.04.02.cpp
Rewrite Listing 4.4, using the C++ string class instead of char 
arrays.
*/

#include <iostream>
#include <string>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter your name:" << endl;
    std::string name;
    getline(cin, name);

    cout << "Enter your favorite dessert:" << endl;
    std::string dessert;
    getline(cin, dessert);

    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << "." << endl;

    return 0; 
}
