/* ex.05.01.cpp
Write a program that requests the user to enter two integers.
The program should then calculate and report the sum of all 
the integers between and including the two integers. At this 
point, assume that the smaller integer is entered first. For 
example, if the user enters 2 and 9, the program should report 
that the sum of all the integers from 2 through 9 is 44.
*/

#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    cout << "Enter two integers" << endl;
    cout << "the first: ";
    int first;
    cin >> first;
    cout << "the second: ";
    int second;
    cin >> second;

    int sum = 0;
    for (int i = first; i <= second; i++) {
        sum += i;
    }

    cout << "The sum of all the integers from " << first;
    cout << " to " << second << " is " << sum << endl;

    return 0; 
}
