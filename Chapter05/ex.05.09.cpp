/* ex.05.09.cpp
Write a program that matches the description of the program in 
Programming Exercise 8, but use a string class object instead 
of an array. Include the string header file and use a relational 
operator to make the comparison test.
*/

#include <iostream>
#include <string>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter words (to stop, type the word done): \n";
    std::string word;
    cin >> word;

    int count = 0;
    while(word != "done")
    {
        ++count;
        cin >> word;
    }

    cout << "You entered a total of " << count << " words." << endl;	

    return 0;
}
