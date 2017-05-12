// ex.10.02.person.cpp -- Person class implementation

#include <iostream>
#include "person.h"

// constructor #2
Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strcpy_s(fname, 25, fn);
}

void Person::Show() const
{
    std::cout << fname << " " << lname << std::endl;
}

void Person::FormalShow() const
{
    std::cout << lname << " " << fname << std::endl;
}