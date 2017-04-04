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
	float diameter;
	float weight;
};

int main()
{
	using namespace std;
	
	Pizza analysis;

	cout << "Enter the name of the pizza company: ";
	cin.getline(analysis.company, 20);
	cout << "Enter the diameter of the pizza (in centimeters): ";
	cin >> analysis.diameter;
	cout << "Enter the weight of the pizza (in grams): ";
	cin >> analysis.weight;

	cout << "The name of the pizza company: " 
		 << analysis.company << endl;
	cout << "The diameter of the pizza: " 
		 << analysis.diameter << " centimeters" << endl;
	cout << "The weight of the pizza: " 
		 << analysis.weight << " grams" << endl;
	
	return 0; 
}