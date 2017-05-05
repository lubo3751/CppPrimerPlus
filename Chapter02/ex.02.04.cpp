/* ex.02.04.cpp
Write a program that asks the user to enter his or her age. 
The program then should display the age in months:

Enter your age: 29
Your age in months is 384.
*/

#include <iostream>

// function prototype
int age_in_months(int);

int main()
{
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;

    age = age_in_months(age);
    std::cout << "Your age in months is " << age << std::endl;

    return 0;
}

int age_in_months(int a)
{
    return a * 12;
}
