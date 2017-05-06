/* ex.08.04
Complete this skeleton by providing the described functions and prototypes. Note
that there should be two show() functions, each using default arguments. Use
const arguments when appropriate. Note that set() should use new to allocate
sufficient space to hold the designated string.The techniques used here are similar
to those used in designing and implementing classes. (You might have to alter the
header filenames and delete the using directive, depending on your compiler.)
*/

#include <iostream>
using namespace std;
#include <cstring> // for strlen(), strcpy()

struct stringy {
    char * str; // points to a string
    int ct; // length of string (not counting '\0')
};

// prototypes for set(), show(), and show() go here
void set(stringy &, const char *);
void show(const stringy &, int repeat = 1);
void show(const char *, int repeat = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
	
    set(beany, testing); // first argument is a reference,
            // allocates space to hold copy of testing,
            // sets str member of beany to point to the
            // new block, copies testing to new block,
            // and sets ct member of beany
    show(beany); // prints member string once
    show(beany, 2); // prints member string twice
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing); // prints testing string once
    show(testing, 3); // prints testing string thrice
    show("Done!");

    delete beany.str;
    return 0;
}

void set(stringy & s, const char c[])
{
    int len = strlen(c);            // length of testing 
    char * pc = new char [len+1];   // space to hold copy of testing
    s.str = pc;                 // str member of beany points to the new block
    strcpy(pc, c);        // copy testing to the new block
    s.ct = len;                  // sets ct member of beany
}

void show(const stringy & s, int repeat)
{
    for (int i = 0; i < repeat; ++i){
        cout << s.str << endl;
    }
}

void show(const char * s, int repeat)
{
    for (int i = 0; i < repeat; ++i){
        cout << s << endl;
    }
}
