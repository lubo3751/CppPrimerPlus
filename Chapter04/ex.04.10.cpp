/* ex.04.10.cpp
Write a program that requests the user to enter three times for 
the 40-yd dash (or 40-meter, if you prefer) and then displays 
the times and the average. Use an array object to hold the data. 
(Use a built-in array if array is not available.)
*/

#include <iostream>
#include <array>

int main(void)
{
    using std::cout;
    using std::cin;
    using std::endl;

    std::array<double, 3> times;

    cout << "Enter three times for the 40-yd dash" << endl;
    cout << "The first time: ";
    cin >> times[0];
    cout << "The second time: ";
    cin >> times[1];
    cout << "The third time: ";
    cin >> times[2];

    double average = (times[0] + times[1] + times[2]) / 3; 

    cout << "The times are " << times[0] << ", ";
    cout << times[1] << ", " << times[2] << endl;
    cout << "Their average is " << average << endl;

    return 0;
}
