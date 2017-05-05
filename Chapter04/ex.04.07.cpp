/* ex.04.07.cpp
William Wingate runs a pizza-analysis service. For each pizza, he needs to record
the following information:
. The name of the pizza company, which can consist of more than one word
. The diameter of the pizza
. The weight of the pizza
Devise a structure that can hold this information and write a program that uses a
structure variable of that type.The program should ask the user to enter each of the
preceding items of information, and then the program should display that information.
Use cin (or its methods) and cout.
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

    Pizza analysis;

    cout << "Enter the name of the pizza company: ";
    cin.getline(analysis.company, 20);
    cout << "Enter the diameter of the pizza (in centimeters): ";
    cin >> analysis.diameter;
    cout << "Enter the weight of the pizza (in grams): ";
    cin >> analysis.weight;

    cout << "The name of the pizza company: ";
    cout << analysis.company << endl;
    cout << "The diameter of the pizza: ";
    cout << analysis.diameter << " centimeters" << endl;
    cout << "The weight of the pizza: ";
    cout << analysis.weight << " grams" << endl;

    return 0; 
}
