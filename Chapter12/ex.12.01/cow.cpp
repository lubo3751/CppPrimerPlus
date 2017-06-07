// cow.cpp -- class Cow methods
#include <cstring>
#include "cow.h"     // includes <iostream>

Cow::Cow()
{
    std::cout << "Cow() called\n";            // comment out to make it silent
    strcpy_s(name, 20, "unknown");
    hobby = new char[3];
    strcpy_s(hobby, 3, "NA");
    weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    std::cout << "Cow(nm,ho,wt) called\n";    // comment out to make it silent
    strcpy_s(name, 20, nm);
    hobby = new char[strlen(ho)+1];
    strcpy_s(hobby, strlen(ho)+1, ho);
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    std::cout << "Cow(c) called\n";           // comment out to make it silent
    strcpy_s(name, 20, c.name);
    hobby = new char[strlen(c.hobby)+1];
    strcpy_s(hobby, strlen(c.hobby)+1, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    std::cout << "~Cow() called\n";           // comment out to make it silent
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    std::cout << "operator=() called\n";      // comment out to make it silent
    if (this == &c)
        return *this;
    strcpy_s(name, 20, c.name);
    delete [] hobby;
    hobby = new char[strlen(c.hobby)+1];
    strcpy_s(hobby, strlen(c.hobby)+1, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const // display all cow data
{
    std::cout << name << ", hobby: " << hobby 
              << ", weigt: " << weight << "Kg\n";
}