// ex.12.01.cpp -- short program that uses 
// all the member functions of Cow class
// compile with cow.cpp
#include <iostream>
#include "cow.h"

int main()
{
    Cow c1;
    c1.ShowCow();
    Cow c2("Strawberry", "chewing", 150.0);
    c2.ShowCow();
    Cow c3(c2);
    c3.ShowCow();
    c1 = c3;
    c1.ShowCow();
    return 0;
}