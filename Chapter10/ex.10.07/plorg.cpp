// ex.10.07.plorg.cpp -- Plorg class implementation
#include <iostream>
#include <cstring>
#include "plorg.h"

namespace PLORG
{
    Plorg::Plorg(char name[], int ci)
    {
        strcpy_s(m_name, 19, name);
        m_ci = ci;
    }

    void Plorg::reset_ci(int ci)
    {
        m_ci = ci;
    }

    void Plorg::report()
    {
        std::cout << "name: " << m_name << "\nCI: " << m_ci << "\n\n";
    } 
}
