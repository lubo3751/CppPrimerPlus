/* ex.08.01
Write a function that normally takes one argument, the address of a string, and
prints that string once. However, if a second, type int, argument is provided and is
nonzero, the function should print the string a number of times equal to the number
of times that function has been called at that point. (Note that the number of
times the string is printed is not equal to the value of the second argument; it is
equal to the number of times the function has been called.) Yes, this is a silly function,
but it makes you use some of the techniques discussed in this chapter. Use the
function in a simple program that demonstrates how the function works.
*/

#include <iostream>

void show_string(const char *, int n = 0);

int main()
{
    show_string("first");
    show_string("second", -2);
    show_string("third");
    show_string("fourth", 9);
    return 0;
}

void show_string(const char * s, int n)
{
    static int count = 0;

    if (n)
    {
        ++count;
        for (int i = 0; i < count; ++i){	
            std::cout << s << std::endl;
	}
    }
    else
    {
        ++count;
        std::cout << s << std::endl;
    }
}
