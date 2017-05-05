/* ex.7.10 
Design a function calculate() that takes two type double values and a pointer to
a function that takes two double arguments and returns a double.The
calculate() function should also be type double, and it should return the value
that the pointed-to function calculates, using the double arguments to
calculate(). For example, suppose you have this definition for the add()
function:
double add(double x, double y)
{
    return x + y;
}
Then, the function call in the following would cause calculate() to pass the values
2.5 and 10.4 to the add() function and then return the add() return value
(12.9):
double q = calculate(2.5, 10.4, add);
Use these functions and at least one additional function in the add() mold in a
program.The program should use a loop that allows the user to enter pairs of numbers.
For each pair, use calculate() to invoke add() and at least one other function.
If you are feeling adventurous, try creating an array of pointers to add()-style
functions and use a loop to successively apply calculate() to a series of functions
by using these pointers. Hint: Here’s how to declare such an array of three pointers:
double (*pf[3])(double, double);
You can initialize such an array by using the usual array initialization syntax and
function names as addresses. 
*/

#include <iostream>

const int SIZE = 3;
const char * Txt[SIZE] = {" + ", " * ", " - "};  // aids printing results

// function prototypes
double calculate(double, double, double (*pf)(double, double));
double add(double, double);
double multiply(double, double);
double subtract(double, double);

int main()
{
    using namespace std;
    // array of pointers to functions
    double (*apf[SIZE])(double, double) = {add, multiply, subtract};

    cout << "Enter two numbers: "; 
    double n1, n2;
    while (cin >> n1 >> n2) // quits when non-number is entered
    {
        // prints calculations (addition, multiplication, subraction)
        for (int i = 0; i < SIZE; i++) {   
            cout << n1 << Txt[i] << n2 << " = " << calculate(n1, n2, apf[i]) << endl;
        }
        cout << "Enter another two numbers <q to terminate>: ";
    }
    cout << "Bye" << endl;
    return 0;
}

double calculate(double x, double y, double (*pf)(double, double))
{
    return pf(x, y);
}

double add(double x, double y)
{
    return x + y;
}

double multiply(double x, double y)
{
    return x * y;
}

double subtract(double x, double y)
{
    return x - y;
}
