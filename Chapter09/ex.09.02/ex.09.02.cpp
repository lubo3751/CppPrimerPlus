// ex.09.02.cpp

#include <iostream>
#include <string>

// function prototype
void strcount(std::string str);

int main()
{
    using namespace std;
    string input;

    cout << "Enter a line:\n";
    getline(cin, input);
    while (input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
// code to keep window open for MSVC++
/*
cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0;
}

void strcount(std::string str)
{
    using namespace std;
    static int total = 0;        // static local variable
	
    cout << "\"" << str <<"\" contains ";
	int count = str.length();    // automatic local variable
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}