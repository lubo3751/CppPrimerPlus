/* ex.07.07 
Redo Listing 7.7, modifying the three array-handling functions to each use two
pointer parameters to represent a range.The fill_array() function, instead of
returning the actual number of items read, should return a pointer to the location
after the last location filled; the other functions can use this pointer as the second
argument to identify the end of the data. 
*/

#include <iostream>

const int MAX = 5;

// function prototypes
double * fill_array(double *begin, const double *end);
void show_array(const double *begin, const double *end);  // doesn't change data
void revalue(double r, double *begin, const double *end);

int main()
{
    using namespace std;
    double properties[MAX];

    double *end = fill_array(properties, properties+MAX);
    show_array(properties, end);
    if (end > properties)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
	    }
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "Done." << endl;
    return 0;
}

double * fill_array(double *begin, const double *end)
{
    using namespace std;
    double temp;
    double *pt;
    for (pt = begin; pt != end; pt++)
    {
        cout << "Enter value #" << (pt - begin + 1) << ": ";
        cin >> temp;
        if (!cin) {  // bad input
            cin.clear();
            while (cin.get() != '\n') {
                continue;
	    }
           cout << "Bad input; input process terminated." << endl;
           break;
        } else if (temp < 0) {    // signal to terminate
            break;
	}
        *pt = temp;
    }
    return pt;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double *begin, const double *end)
{
    using namespace std;
    for (const double *pt = begin; pt != end; pt++)
    {
        cout << "Property #" << (pt - begin + 1) << ": $";
        cout << *pt << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double *begin, const double *end)
{
    for (double *pt = begin; pt != end; pt++)
        *pt *= r;
}
