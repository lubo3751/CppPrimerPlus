// dma.cpp  -- abcDMA class, baseDMA class, lacksDMA class, 
//             and hasDMA class implementation

#include "dma.h"
#include <cstring>

/*
 * abcDMA methods
 */
abcDMA::abcDMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    strcpy_s(label, std::strlen(l) + 1, l);
    rating = r;
}

abcDMA::abcDMA(const abcDMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    strcpy_s(label, std::strlen(rs.label) + 1, rs.label);
    rating = rs.rating;
}

abcDMA & abcDMA::operator=(const abcDMA & rs)
{
    if (this == &rs) return *this;
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    strcpy_s(label, std::strlen(rs.label) + 1, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const abcDMA & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

void abcDMA::View() const
{
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

/*
 * lacksDMA methods
 */
lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : abcDMA(l, r)
{
    strcpy_s(color, COL_LEN, c);
}

lacksDMA::lacksDMA(const char * c, const abcDMA & rs)
    : abcDMA(rs) {
    strcpy_s(color, COL_LEN, c);
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const abcDMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

void lacksDMA::View() const
{
    abcDMA::View();
    std::cout << "Color: " << color << std::endl;
}

/*
 * hasDMA methods
 */
hasDMA::hasDMA(const char * s, const char * l, int r)
         : abcDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    strcpy_s(style, std::strlen(s) + 1, s);
}

hasDMA::hasDMA(const char * s, const abcDMA & rs)
         : abcDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    strcpy_s(style, std::strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA & hs)
         : abcDMA(hs)
{
    style = new char[std::strlen(hs.style) + 1];
    strcpy_s(style, std::strlen(hs.style) + 1, hs.style);
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs) return *this;
    abcDMA::operator=(hs);  // copy base portion
    delete [] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    strcpy_s(style, std::strlen(hs.style) + 1, hs.style);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const abcDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}

void hasDMA::View() const
{
    abcDMA::View();
    std::cout << "Style: " << style << std::endl;
}
