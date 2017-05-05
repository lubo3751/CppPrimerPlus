/* ex.05.10.cpp
Write a program using nested loops that asks the user to enter 
a value for the number of rows to display. It should then display 
that many rows of asterisks, with one asterisk in the first row, 
two in the second row, and so on. For each row, the asterisks are 
preceded by the number of periods needed to make all the rows 
display a total number of characters equal to the number of rows. 
A sample run would look like this:

Enter number of rows: 5
....*
...**
..***
.****
*****
*/

#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter number of rows: ";
    int rows;
    cin >> rows;

    for (int i = 1; i <= rows; ++i)
    {
        for (int j = rows - i; j > 0; --j) {
            cout << '.';
        }
        for (int j = i; j > 0; --j) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}
