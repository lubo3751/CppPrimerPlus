/* ex.07.02 
Write a program that asks the user to enter up to 10 golf scores, which are to be
stored in an array.You should provide a means for the user to terminate input prior
to entering 10 scores.The program should display all the scores on one line and
report the average score. Handle input, display, and the average calculation with
three separate array-processing functions. 
*/

#include <iostream>

const int MAX = 10;

// function prototypes
int getScores(double []);
void display(const double [], int);
double average(const double [], int);

int main()
{
    using namespace std;
    double golf[MAX];
    int size = getScores(golf);

    if (size) {
        display(golf, size);
        cout << "The average score: " << average(golf, size) << endl;
    } else {
        cout << "No scores to display" << endl;
    }
    return 0;
}

int getScores(double arr[])
{
    using namespace std;
    cout << "Please enter your golf scores." << endl;
    cout << "You may enter up to " << MAX;
    cout << " rounds <q to terminate>" << endl;
    cout << "round #1: ";
    int i = 0;
    while (i < MAX && cin >> arr[i]) {
        if (++i < MAX) {
            cout << "round #" << i+1 << ": ";
	}
    }
    return i;
}

void display(const double arr[], int s)
{
    using namespace std;
    cout << "Your scores: ";
    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double average(const double arr[], int size)
{
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total / size;
}
