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

void set_CandyBar(CandyBar &, const char * s = "Millennium Munch", 
                           double w = 2.85, int c = 350);
void show_CandyBar(const CandyBar &);

int main()
{
    CandyBar candy_bar;
    const char * brand = "Snikers";
    const double weight = 1.66;
    const int calories = 229;

    set_CandyBar(candy_bar);
    show_CandyBar(candy_bar);
    std::cout << std::endl;
    set_CandyBar(candy_bar, brand, weight, calories);
    show_CandyBar(candy_bar);
    std::cout << std::endl;

    return 0;
}

void set_CandyBar(CandyBar & cb, const char * s, double w, int c)
{
    cb.brand = s;
    cb.weight = w;
    cb.calories = c;
}

void show_CandyBar(const CandyBar & cb)
{
    std::cout << "brand name: " << cb.brand << std::endl;
    std::cout << "weight: " << cb.weight << " oz" << std::endl;
    std::cout << "calories: " << cb.calories << std::endl;
}
