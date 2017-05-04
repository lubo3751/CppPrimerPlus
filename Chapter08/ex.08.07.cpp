/* ex.08.07
Modify Listing 8.14 so that it uses two template functions called SumArray() to
return the sum of the array contents instead of displaying the contents.The program
now should report the total number of things and the sum of all the debts.
*/

#include <iostream>

template <typename T>        // template A
T SumArray(T arr[], int n);

template <typename T>        // template B
T SumArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3]; 

    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    
    cout << "The total number of things: ";
    // things is an array of int
    cout << SumArray(things, 6) << endl; // uses template A
    cout << "The sum of all the debts: ";
    // pd is an array of pointers to double
    cout << SumArray(pd, 3) << endl;     // uses template B (more specialized)
    // cin.get();
    return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = 0;    
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

template <typename T>
T SumArray(T * arr[], int n)
{
    T sum = 0;
    for (int i = 0; i < n; i++){
        sum += *arr[i];
    }
    return sum;
}
