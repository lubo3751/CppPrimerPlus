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
    using std::cout;
    using std::endl;
    char filename[SIZE];
    std::ifstream inFile;        // object for handling file input

    // ask the user which file to read
    cout << "Enter name of data file: ";
    std::cin.getline(filename, SIZE);
    inFile.open(filename);  // associate inFile with a file

    // check the file has opened
    if (!inFile.is_open())  // failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating." << endl;
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
    if (inFile.eof()) {
        cout << "End of file reached." << endl;
    } else if (inFile.fail()) {
        cout << "Input terminated by data mismatch." << endl;
    } else {
        cout << "Input terminated for unknown reason." << endl;
    }

    // print results
    if (count == 0) {
        cout << "No data processed." << endl;
    } else {
        cout << "Characters read: " << count << endl;
    }
    
    inFile.close();         // finished with the file
    return 0;
}
