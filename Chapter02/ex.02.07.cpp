/* ex.02.07.cpp
Write a program that asks the user to enter an hour value and 
a minute value. The main() function should then pass these two 
values to a type void function that displays the two values in 
the format shown in the following sample run:

Enter the number of hours: 9
Enter the number of minutes: 28
Time: 9:28
*/

#include <iostream>

// function prototype
void show_time(int, int);

int main()
{
    std::cout << "Enter the number of hours: ";
    int hours;
    std::cin >> hours;	

    std::cout << "Enter the number of minutes: ";
    int minutes;
    std::cin >> minutes;

    show_time(hours, minutes);

    return 0;
}

void show_time(int h, int m)
{
    std::cout << "Time: " << h << ':' << m << std::endl;
}
