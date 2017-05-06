/* ex.08.05
Write a template function max5() that takes as its argument an array of five items
of type T and returns the largest item in the array. (Because the size is fixed, it can
be hard-coded into the loop instead of being passed as an argument.) Test it in a
program that uses the function with an array of five int value and an array of five
double values.
*/

#include <iostream>

const int SIZE = 5;

template <typename T>
T max5(const T ar[]);

int main()
{
    int integers[SIZE] = {4, 6, 2, 8, 1};
    std::cout << "largest integer: " << max5(integers) << std::endl;

    double doubles[SIZE] = {3.5, 6.3, 9.8, 1.3, 7.4};
    std::cout << "largest double: " << max5(doubles) << std::endl;

    return 0;
}

template <typename T>
T max5(const T ar[])
{
    T max = ar[0];
    for (int i = 1; i < SIZE; ++i){
        if (max < ar[i]){
            max = ar[i];
        }
    }
    return max;
}
