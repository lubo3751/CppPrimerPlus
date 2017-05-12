// ex.10.04.main.cpp -- using namespaces
#include <iostream>
#include "namesp.h"

int main(void)
{
    using SALES::Sales;
    const int Q = 4;

    Sales s1;
    s1.setSales();
    std::cout << "Sales 1";
    s1.showSales();
    
    const double sales[Q] = {2535.3, 12542.4, 34213.6, 4290}; 
    Sales s2;
    s2 = Sales(sales, Q);
    std::cout << "Sales 2";
    s2.showSales();

    return 0;
}
