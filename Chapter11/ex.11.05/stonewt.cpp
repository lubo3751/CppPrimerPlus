// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = LBS;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
    mode = STN;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    mode = STN;
}

Stonewt::~Stonewt()         // destructor
{
}

void Stonewt::stn_mode()
{
    mode = STN;
}

void Stonewt::lbs_mode()
{
    mode = LBS;
}

Stonewt Stonewt::operator+(const Stonewt & sw) const
{
    return pounds + sw.pounds;
}

Stonewt Stonewt::operator-(const Stonewt & sw) const
{
    return pounds - sw.pounds;
}

Stonewt Stonewt::operator*(double n) const
{
    return pounds * n;
}



std::ostream & operator<<(std::ostream & os, const Stonewt & sw)
{
    if (sw.mode == Stonewt::STN)
        os << sw.stone << " stone, " << sw.pds_left << " pounds\n";
    else if (sw.mode == Stonewt::LBS)
        os << sw.pounds << " pounds\n";
    else 
        os << "Incorrect mode";
    return os;
}
