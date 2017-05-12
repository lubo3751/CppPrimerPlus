// ex.10.02.main.cpp -- using the Person class
// compile with person.cpp

#include <iostream>
#include "person.h"

int main()
{
    Person one;                      // use default constructor
    Person two("Smythecraft");       // use #2 with one default argument
    Person three("Dimwiddy", "Sam"); // use #2, no defaults
    
    one.Show();
    one.FormalShow();
    std::cout << std::endl;
    
    two.Show();
    two.FormalShow();
    std::cout << std::endl;

    three.Show();
    three.FormalShow();
    std::cout << std::endl;
    
    return 0;
}