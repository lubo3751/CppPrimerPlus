// golf.cpp -- function definitions

#include <iostream>
#include <cstring>
#include "chaff.h"

void set_ptChAr(chaff * pChaffAr)
{
    for (int i = 0; i < N; i++)
    {
        set_dross(pChaffAr[i], i);
        set_slag(pChaffAr[i], i);
    }
}

void set_dross(chaff & ch, int i)
{
    using std::cin;
	using std::cout;
	using std:: endl;
	using std::strcpy;

    char dross_holder[20];
    cout << "Enter a dross" << i+1 << " name: ";
	cin.get(dross_holder, 20);
	// prompt user to reenter if nothing entered
	while (strlen(dross_holder) == 0)
	{
		cin.clear();
		cin.get();
		cout << "Error. Nothing entered." << endl;
		cout << "Enter a dross" << i+1 << " name: ";
		cin.get(dross_holder, 20);
	}
	// discard remaining characters
	while (cin.get() != '\n')
		continue;
	strcpy(ch.dross, 20, dross_holder);
}

void set_slag(chaff & ch, int i)
{
	while (1)
    {
        using std::cin;
    	using std::cout;
	    using std:: endl;
	    using std::strcpy;

        cout << "Enter a slag" << i+1 << " number: ";
        cin >> ch.slag;
        if (cin.fail())             // no extraction took place
        {
            cin.clear();            // clear error flags
            cin.ignore(1000, '\n'); // clear bad input from the stream
            cout << "Error. Not an integer." << endl;
            continue;               // try again
        }
        cin.ignore(1000, '\n'); // clear additional input from the stream
        if (cin.gcount() > 1)   // if more than one additional char cleared
        {                       // we'll consider this input to be invalid
            cout << "Error. Not an integer." << endl;
            continue;           // try again
        }
        break;
    }
}

void show_ptChAr(chaff * pChaffAr)
{
    for (int i = 0; i < N; i++) 
    {
        std::cout << "dross" << i+1 << ": " << pChaffAr[i].dross << std::endl;
        std::cout << "slag" << i+1 << ": " << pChaffAr[i].slag << std::endl;
	}
}

