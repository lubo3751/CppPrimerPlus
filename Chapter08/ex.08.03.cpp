/* ex.08.03
Write a function that takes a reference to a string object as its parameter and that
converts the contents of the string to uppercase. Use the toupper() function
described in Table 6.4 of Chapter 6.Write a program that uses a loop which allows
you to test the function with different input.A sample run might look like this:
Enter a string (q to quit): go away
GO AWAY
Next string (q to quit): good grief!
GOOD GRIEF!
Next string (q to quit): q
Bye.
*/

#include <iostream>
#include <string>
#include <cctype>

void to_upper(std::string &);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    cout << "Enter a string (q to quit): ";
    std::string text;
    while (getline(cin, text) && text != "q")
    {
        to_upper(text);
        cout << text << endl;
        cout << "Next string (q to quit): ";
    }
    cout << "Bye." << endl;
    return 0;
}

void to_upper(std::string & s)
{
    for (int i = 0; s[i]; ++i){
        s[i] = toupper(s[i]);
    }
}
