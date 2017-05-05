/* ex.07.01
Write a program that repeatedly asks the user to enter pairs of numbers until at
least one of the pair is 0. For each pair, the program should use a function to calculate
the harmonic mean of the numbers.The function should return the answer to
main(), which should report the result.The harmonic mean of the numbers is the
inverse of the average of the inverses and can be calculated as follows:
harmonic mean = 2.0 × x × y / (x + y)
*/

#include <iostream>

double harmonicMean(double, double);

int main()
{
    using namespace std;
    cout << "Enter two numbers (0 to quit): ";
    double num1, num2;

    while (cin >> num1 >> num2 && num1 != 0 && num2 != 0)
    {
        cout << "Their Harmonic Mean is " << harmonicMean(num1, num2);
        cout << "\nEnter two numbers (0 to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}

double harmonicMean(double n1, double n2)
{
    return 2.0 * n1 * n2 / (n1 + n2); 
}
