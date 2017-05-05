/* ex.06.01.cpp
Write a program that reads keyboard input to the @ symbol and 
that echoes the input except for digits, converting each uppercase 
character to lowercase, and vice versa. (Don’t forget the cctype 
family.)
*/

#include <iostream>
#include <cctype>

int main()
{
    using namespace std;
    char ch;
    cin.get(ch);
    while (ch != '@')
    {
        if (isdigit(ch)) {
            cin.get(ch);
            continue;
        } else if (isupper(ch)) {
            ch = tolower(ch);
        } else {
            ch = toupper(ch);
        }
        cout << ch;
        cin.get(ch);
    }
    cout << endl;
    return 0; 
}
