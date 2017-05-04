// ex.09.04.main.cpp -- using namespaces
#include <iostream>
#include "namesp.h"

int main(void)
{
	using namespace SALES;
    Sales s1, s2;

    setSales(s1);
    std::cout << "Sales 1";
    showSales(s1);
    
    const double sales[QUARTERS] = {2535.3, 12542.4, 34213.6, 4290}; 
    setSales(s2, sales, QUARTERS);
    std::cout << "Sales 2";
    showSales(s2);

	return 0;
}