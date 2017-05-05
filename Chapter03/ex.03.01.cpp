/* ex.03.01.cpp
Write a short program that asks for your height in integer 
inches and then converts your height to feet and inches. Have 
the program use the underscore character to indicate where to 
type the response. Also use a const symbolic constant to 
represent the conversion factor.
*/

#include <iostream>

const int InchPerFoot = 12;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter your height in inches: ___\b\b\b ";
    int inches;
    cin >> inches;
    
    int feet = inches / InchPerFoot;
    int remInches = inches % InchPerFoot;

    cout << inches << " inches are " << feet;
    cout << " feet and " << remInches << " inches." << endl;
	
    return 0; 
}
