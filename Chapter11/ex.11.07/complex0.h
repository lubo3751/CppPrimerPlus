// complex0.h -- complex class definition
#ifndef STOCK00_H_
#define STOCK00_H_ 
#include <iostream>

class complex  // class declaration
{
private: 
    double one;
    double two;
public:
    complex(double o, double t);                      // constructor
    complex();                                        // default constructor
    complex operator+(const complex & c) const;       // + overloading
    complex operator-(const complex & c) const;       // - overloading
    complex operator*(const complex & c) const;       // * overloading
    complex operator*(double n) const;                // * overloading
    complex operator~() const;                        // ~ overloading
    // overloading using friend functions
    friend complex operator*(double n, const complex & c) { return c * n; };
    friend std::istream & operator>>(std::istream & is, complex & c);
    friend std::ostream & operator<<(std::ostream & os, const complex & c);
};
#endif