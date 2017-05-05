/* ex.04.04.cpp 
Write a program that asks the user to enter his or her first name 
and then last name, and that then constructs, stores, and displays 
a third string, consisting of the user’s last name followed by 
a comma, a space, and first name. Use string objects and methods 
from the string header file.A sample run could look like this:
Enter your first name: Flip
Enter your last name: Fleming
Here’s the information in a single string: Fleming, Flip
 */

#include <iostream>
#include <string>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter your first name: ";
    std::string first_name;
    cin >> first_name;

    cout << "Enter your last name: ";
    std::string last_name;
    cin >> last_name;

    std::string whole_name;
    whole_name = last_name;
    whole_name += ", ";
    whole_name += first_name;

    cout << "Here's the information in a single string: " << whole_name << endl;

    return 0; 
}
