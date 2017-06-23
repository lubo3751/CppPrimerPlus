// port.cpp -- Port class and VintagePort class implementation
#include <string>
#include "port.h"

/*
 * Port methods
 */
Port::Port(const char * br, const char * st, int b) : bottles(b)
{
    brand = new char[strlen(br) + 1];
    strcpy_s(brand, strlen(br) + 1, br);
    strcpy_s(style, 20, st);
}

Port::Port(const Port & p) : bottles(p.bottles)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy_s(brand, strlen(p.brand) + 1, p.brand);
    strcpy_s(style, 20, p.style);
}

Port & Port::operator=(const Port & p)
{
    if (this == &p)
        return *this;
    delete[] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy_s(brand, strlen(p.brand) + 1, p.brand);
    strcpy_s(style, 20, p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

/*
 * VintagePort methods
 */
VintagePort::VintagePort() : Port("none", "vintage"), year(0)
{
    nickname = new char[5];
    strcpy_s(nickname, 5, "none");
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) 
    : Port(br, "vintage", b), year(y)
{ 
    nickname = new char[strlen(nn) + 1];
    strcpy_s(nickname, strlen(nn) + 1, nn);
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp), year(vp.year)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    cout << (const Port &)vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}
