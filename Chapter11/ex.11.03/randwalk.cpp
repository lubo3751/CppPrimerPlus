// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step; 
    Vector result(0.0, 0.0); 
    unsigned long steps = 0, highest = 0, lowest = 1000000000, sum = 0;
    unsigned int trials;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        cout << "Enter number of trials: ";
        if (!(cin >> trials))
            break;
        for (int i = 0; i < trials; ++i)
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            highest = highest < steps ? steps : highest;
            lowest = lowest > steps ? steps : lowest;
            sum += steps;
            steps = 0;
            result.reset(0.0, 0.0);
        }

        cout << "After " << trials << " trials,\n"
             << "the highest number of steps was: " << highest << ",\n"
             << "the lowest number of steps was: " << lowest << ",\n"
             << "and the average number of steps was: " << sum/trials  << ".\n"
             << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
/* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0; 
}
