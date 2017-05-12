// ex.10.06.main.cpp -- using the Move class
// compile with move.cpp
#include <iostream>
#include "move.h"

int main()
{
    Move m1;
    m1.showmove();
    m1.reset(4.5, 7.3);
    m1.showmove();

    Move m2 = Move(9.9, 10.0);
    m2.showmove();

    Move m3;
    m3 = m2.add(m1);
    m3.showmove();
    m3.reset();
    m3.showmove();
    
    return 0;
}