// complex0.cpp -- complex class implementation
#include "complex0.h"   // includes <iostream>

// constructor
complex::complex(double o, double t)
{
    one = o;
    two = t;
}

complex::complex()  // default constructor 
{
    one = two = 0.0;
}

complex complex::operator+(const complex & c) const
{
    return complex(one + c.one, two + c.two);
}

complex complex::operator-(const complex & c) const
{
    return complex(one - c.one, two - c.two);
}

complex complex::operator*(const complex & c) const
{
    return complex(one * c.one - two * c.two, one * c.one + two * c.two);
}

complex complex::operator*(double n) const
{
    return complex(one * n, two * n);
}

complex complex::operator~() const
{
    return complex(one, -two);
}

std::istream & operator>>(std::istream & is, complex & c)
{
    std::cout << "real: ";
    if (!(is >> c.one))
        return is;
    std::cout << "imaginary: ";
    is >> c.two;
    return is;
}

std::ostream & operator<<(std::ostream & os, const complex & c)
{
    os << "(" << c.one << "," << c.two << "i)";
    return os;
}