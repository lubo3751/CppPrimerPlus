/* ex.07.03 
Here is a structure declaration:
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
a. Write a function that passes a box structure by value and that displays the
value of each member.
b. Write a function that passes the address of a box structure and that sets the
volume member to the product of the other three dimensions.
c. Write a simple program that uses these two functions. 
*/

#include <iostream>

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

// function prototypes
void userInput(box *);
void addVolume(box *);
void display(box);

int main()
{
    using namespace std;
    box container;

    userInput(&container);
    addVolume(&container);
    display(container);

    return 0;
}

void userInput(box *ptr)
{
    using namespace std;
    cout << "Enter the maker: ";
    cin.getline(ptr->maker, 40);
    cout << "Enter the height: ";
    cin >> ptr->height;
    while (!cin || ptr->height <= 0)    // bad input
    {
        cin.clear();
        while (cin.get() != '\n') {
            continue;
	}
        cout << "Bad input, enter the height again: ";
        cin >> ptr->height;
    }
    cout << "Enter the width: ";
    cin >> ptr->width;
    while (!cin || ptr->width <= 0)    // bad input
    {
        cin.clear();
        while (cin.get() != '\n') {
            continue;
	}
        cout << "Bad input, enter the width again: ";
        cin >> ptr->width;
    }
    cout << "Enter the length: ";
    cin >> ptr->length;
    while (!cin || ptr->length <= 0)    // bad input
    {
        cin.clear();
        while (cin.get() != '\n') {
            continue;
	}
        cout << "Bad input, enter the length again: ";
        cin >> ptr->length;
    }
}

void addVolume(box *ptr)
{
    ptr->volume = ptr->height * ptr->width * ptr->length;
}

void display(box b)
{
    using namespace std;
    cout << "The box details:";
    cout << endl << "Maker: " << b.maker;
    cout << endl << "Height: " << b.height;
    cout << endl << "Width: " << b.width;
    cout << endl << "Length: " << b.length;
    cout << endl << "Volume: " << b.volume << endl;
}
