/* ex.08.02
The CandyBar structure contains three members.The first member holds the brand
name of a candy bar.The second member holds the weight (which may have a fractional
part) of the candy bar, and the third member holds the number of calories
(an integer value) in the candy bar.Write a program that uses a function that takes
as arguments a reference to CandyBar, a pointer-to-char, a double, and an int and
uses the last three values to set the corresponding members of the structure.The last
three arguments should have default values of “Millennium Munch,” 2.85, and 350.
Also the program should use a function that takes a reference to a CandyBar as an
argument and displays the contents of the structure. Use const where appropriate.
*/

#include <iostream>
#include <string>

struct CandyBar
{
	std::string brand;
	double weight;
	int calories;
};

void show(const CandyBar &);
void set(CandyBar &, const char * s = "Millennium Munch", 
		  double w = 2.85, int c = 350);

int main()
{
	using namespace std;
	CandyBar snack;
	char name[] = "Snikers";
	double weight = 2.75;
	int calories = 345;

	set(snack);
	show(snack);
	set(snack, name, weight, calories);
	show(snack);
	set(snack);
	show(snack);
	set(snack, name, weight, calories);
	show(snack);

	return 0;
}

void set(CandyBar & candy, const char * s, double w, int c)
{
	candy.brand = s;
	candy.weight = w;
	candy.calories = c;
}

void show(const CandyBar & candy)
{
	using namespace std;
	cout << "brand name: " << candy.brand << endl
		 << "weight: " << candy.weight << endl
		 << "calories: " << candy.calories << endl;
}