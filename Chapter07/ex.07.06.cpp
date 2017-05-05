/* ex.07.06 
Write a program that uses the following functions:
Fill_array() takes as arguments the name of an array of double values and an
array size. It prompts the user to enter double values to be entered in the array. It
ceases taking input when the array is full or when the user enters non-numeric
input, and it returns the actual number of entries.
Show_array() takes as arguments the name of an array of double values and an
array size and displays the contents of the array.
Reverse_array() takes as arguments the name of an array of double values and an
array size and reverses the order of the values stored in the array.
The program should use these functions to fill an array, show the array, reverse the
array, show the array, reverse all but the first and last elements of the array, and then
show the array. 
*/

#include <iostream>

const int MAX = 7;

// function prototypes
int fill_array(double[], int);
void show_array(const double[], int);
void reverse_array(double[], int);

int main()
{
    using namespace std;
    double numbers[MAX];

    int size = fill_array(numbers, MAX);
    cout << "You typed:                 "; 
    show_array(numbers, size);
    cout << "After being reversed:      ";
    reverse_array(numbers, size);
    show_array(numbers, size);
    cout << "Again except 1st and last: ";
    reverse_array(numbers+1, size-2);
    show_array(numbers, size);

    return 0;
}

int fill_array(double arr[], int max)
{
    using namespace std;
    cout << "Enter up to " << max << " numbers <q to terminate>" << endl;
    cout << "#1: ";
    int i = 0;
    while (i < max && cin >> arr[i]) {
        if (++i < max) {
            cout << "#" << i+1 << ": ";
	}
    }
    return i;
}

void show_array(const double arr[], int size)
{
    using namespace std;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void reverse_array(double arr[], int size)
{
    double temp;
    int i, j;
    for (j = 0, i = size - 1; j < i; --i, ++j)
    {   // start block
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
