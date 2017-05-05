/* ex.05.03.cpp
Write a program that asks the user to type in numbers.After 
each entry, the program should report the cumulative sum of 
the entries to date.The program should terminate when the user 
enters 0.
*/

#include <iostream>

int main()
{
    std::cout << "Enter a number (0 to quit) : ";
    double number, sum = 0;
    std::cin >> number;
    while (number)
    {
        sum += number;
        std::cout << "The cumulative sum is " << sum << std::endl;
        std::cout << "Enter a number (o to quit) : ";
        std::cin >> number;
    }
    return 0;
}
