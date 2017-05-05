/* ex.02.03.cpp
Write a C++ program that uses three user-defined functions 
(counting main() as one) and produces the following output:

Three blind mice
Three blind mice
See how they run
See how they run

One function, called two times, should produce the first two 
lines, and the remaining function, also called twice, should 
produce the remaining output.
*/

#include <iostream>

// function prototypes
void function_1();
void function_2();

int main()
{
    function_1();
    function_1();
    function_2();
    function_2();
    return 0;
}

void function_1()
{
    std::cout << "Three blind mice" << std::endl;
}

void function_2()
{
    std::cout << "See how they run" << std::endl;
}
