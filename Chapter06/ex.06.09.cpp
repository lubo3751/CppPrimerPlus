/* ex.06.09.cpp
Do Programming Exercise 6 but modify it to get information from a file.The first
item in the file should be the number of contributors, and the rest of the file should
consist of pairs of lines, with the first line of each pair being a contributor’s name
and the second line being a contribution.That is, the file should look like this:
4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000
*/

#include <iostream>
#include <string>
#include <fstream>          // file I/O support
#include <cstdlib>          // support for exit()

const int LIMIT = 10000;

struct donor {
    std::string name;
    double amount;
};

int main()
{
    using std::cout;
    using std::endl;
    char file_name[] = "donors.txt";
    std::ifstream inFile;        // object for handling file input
    inFile.open(file_name);  // associate inFile with a file

    if (!inFile.is_open())  // check the file has opened
    {
        cout << "Could not open the file " << file_name << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }

    int num_of_donors;
    (inFile >> num_of_donors).get();  // read how many donors

    // dynamically allocate array of structures
    donor * pt_donors = new donor[num_of_donors];

    // initialize structure
    for (int i = 0; i < num_of_donors; ++i) 
    {
        getline(inFile, pt_donors[i].name);    // reads donor's name
        (inFile >> pt_donors[i].amount).get(); // reads donor's contribution
    }

    // display Grand Patrons
    cout << "Grand Patrons:" << endl;
    int counter = 0;
    for (int i = 0; i < num_of_donors; ++i) {
        if (pt_donors[i].amount >= LIMIT) {
            cout << pt_donors[i].name << " donated $" << pt_donors[i].amount << endl;
            ++counter;
        }
    }
    if (!counter) {
        cout << "none" << endl;
    }

    // display Patrons
    cout << "Patrons:" << endl;
    counter = 0;
    for (int i = 0; i < num_of_donors; ++i) {
        if (pt_donors[i].amount < LIMIT) {
            cout << pt_donors[i].name << endl;
            ++counter;
        }
    }
    if (!counter) {
        cout << "none" << endl;
    }

    return 0;
}
