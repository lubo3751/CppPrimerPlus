// main.cpp -- solution to exercise 6 chapter 11 of C++ Primer Plus
// compile with stonewt.cpp
#include <iostream>
#include <array>
#include "stonewt.h"

int main()
{
    const int MAX = 6;
    std::array<Stonewt, MAX> arr_stn = {100.0, 200.0, 300.0};
    for (int i = 3; i < MAX; ++i) {
        std::cout << "Enter value for " << i+1 << "th element (in pounds): ";
        std::cin >> arr_stn[i];
    }
    Stonewt stn_11(11, 0.0);
    Stonewt smallest(1000000000.0), largest;
    int over_11_stn = 0;
    for (int i = 0; i < MAX; ++i) {
        if (smallest > arr_stn[i])
            smallest = arr_stn[i];
        else if (largest < arr_stn[i])
            largest = arr_stn[i];

        if (arr_stn[i] > stn_11)
            ++over_11_stn;
    }
    std::cout << "\nThe smallest element is " << smallest << ".\n"
         << "The largest element is " << largest << ".\n"
         << over_11_stn << " elements are greater or equal to 11 stone.\n\n";
/*
    for (int i = 0; i < MAX; ++i)
        cout << arr_stn[i] << endl;

    cout << stn_11 << endl;
*/
    return 0;
}
