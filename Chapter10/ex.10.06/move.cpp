// ex.10.06.move.cpp -- Move class implementation
#include <iostream>
#include "move.h"

namespace MOVE
{
    Move::Move(double a, double b)
    {
        x = a;
        y = b;
    }

    void Move::showmove() const
    {
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl << std::endl;
    }

    Move Move::add(const Move & m) const
    {
        return Move(x + m.x, y + m.y); 
    }

    void Move::reset(double a, double b)
    {
        *this = Move(a, b);
    } 
}