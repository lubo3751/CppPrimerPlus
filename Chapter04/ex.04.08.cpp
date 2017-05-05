/* ex.04.08.cpp
Do Programming Exercise 7 but use new to allocate a structure 
instead of declaring a structure variable.Also have the program 
request the pizza diameter before it requests the pizza company 
name.
*/

#include <iostream>

struct Pizza
{
    char company[20];
    double diameter;
    double weight;
};

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    Pizza * pt_Pizza = new Pizza;

    cout << "Enter the diameter of the pizza (in centimeters): ";
    cin >> pt_Pizza->diameter;
    cin.get();
    cout << "Enter the name of the pizza company: ";
    cin.getline(pt_Pizza->company, 20);
    cout << "Enter the weight of the pizza (in grams): ";
    cin >> pt_Pizza->weight;

    cout << "The name of the pizza company: ";
    cout << pt_Pizza->company << endl;
    cout << "The diameter of the pizza: ";
    cout << pt_Pizza->diameter << " centimeters" << endl;
    cout << "The weight of the pizza: ";
    cout << pt_Pizza->weight << " grams" << endl;

    delete pt_Pizza;

    return 0; 
}
