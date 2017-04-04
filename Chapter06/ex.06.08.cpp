/* ex.06.08.cpp
Write a program that opens a text file, reads it character-by-character to the end of
the file, and reports the number of characters in the file.
*/

#include <iostream>
#include <fstream>          // file I/O support
#include <cstdlib>          // support for exit()

const int SIZE = 60;

int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;        // object for handling file input

	// ask the user which file to read
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);  // associate inFile with a file

	// check the file has opened
    if (!inFile.is_open())  // failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    char ch;
	int count = 0;          // number of characters read

	// read and count character after character
    inFile >> ch;           // get first character
    while (inFile.good())   // while input good and not at EOF
    {
        ++count;            // one more item read
        inFile >> ch;       // get next character
    }

	// check ending condition 
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";

	// print results
	if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Characters read: " << count << endl;
    }
    inFile.close();         // finished with the file
    
    return 0;
}