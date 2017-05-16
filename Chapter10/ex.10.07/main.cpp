// ex.10.07.main.cpp -- using the Plorg class
// compile with plorg.cpp
#include <iostream>
#include "plorg.h"

int main()
{
    using namespace PLORG;
    Plorg p1;
    p1.report();
    p1.reset_ci(33);
    p1.report();

    Plorg p2 = Plorg("Pluregy", 120);
    p2.report();

    Plorg p3 = Plorg("Plargej");
    p3.report();
    p3 = Plorg("Plieryg", 99);
    p3.report();
    p3 = Plorg("Plg");
    p3.report();
    
    
    return 0;
}