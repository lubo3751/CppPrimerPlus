// ex.09.03

#include <iostream>
#include <new>       // for placement new
#include "chaff.h"

static chaff buffer[N];     // chunk of memory

int main()
{
    chaff * pChaffAr = new (buffer) chaff[N];  // use buffer array
    set_ptChAr(pChaffAr);
    show_ptChAr(pChaffAr); 
    return 0;
}