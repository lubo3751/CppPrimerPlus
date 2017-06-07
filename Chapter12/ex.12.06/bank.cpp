// main.cpp -- exercise 6 chapter 12 of C++ Primer Plus
// compile with queue.cpp
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
// setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    Queue line1(10);         // line queue holds up to qs people
    Queue line2(10);
    int hours = 200;        //  hours of simulation
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles
    double perhour = 60;    //  average # of arrival per hour;
    double min_per_cust;    //  average time between arrivals

    Item temp;              //  new customer data
    long turnaways;         //  turned away by full queue
    long customers;         //  joined the queue
    long served;            //  served during the simulation
    long sum_line;          //  cumulative line length
    int wait_time1;         //  time until autoteller is free
    int wait_time2;         //  time until autoteller is free
    long line_wait;         //  cumulative time in line

// running the simulation
    do
    {
        while (line1.dequeue(temp))   // empty line1
            ;
        while (line2.dequeue(temp))   // empty line2
            ;
        turnaways = customers = served = sum_line = line_wait = 0.0;
        wait_time1 = wait_time2 = 0;
        min_per_cust = MIN_PER_HR / --perhour;

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))   // have newcomer
            {
                if (!line1.isfull() && line1.queuecount() < line2.queuecount())
                {
                    customers++;
                    temp.set(cycle);
                    line1.enqueue(temp);  // add newcomer to line1
                }
                else if (!line2.isfull())
                {
                    customers++;
                    temp.set(cycle);
                    line2.enqueue(temp);
                }
                else
                    turnaways++;
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue (temp);      // attend next customer
                wait_time1 = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            sum_line += line2.queuecount();
            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue (temp);      // attend next customer
                wait_time2 = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 > 0)
                wait_time2--;
            sum_line += line2.queuecount();
        }
    } 
    while ( ( (double) line_wait / served ) > 1.03 );

// reporting results
    if (customers > 0)
    {
        cout << perhour << " customers per hour leads to \n"
             << "an average wait time of one minute.\n\n";

        cout << "simulation period: " << hours << " hours\n";
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / 2 / cyclelimit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    // cin.get();
    // cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); 
}
