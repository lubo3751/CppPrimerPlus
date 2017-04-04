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
	float diameter;
	float weight;
};

int main()
{
	using namespace std;

	Pizza *analysis = new Pizza;

	cout << "Enter the diameter of the pizza (in centimeters): ";
	cin >> analysis->diameter;
	cin.get();
	cout << "Enter the name of the pizza company: ";
	cin.getline(analysis->company, 20);
	cout << "Enter the weight of the pizza (in grams): ";
	cin >> analysis->weight;

	cout << "The name of the pizza company: " 
		 << analysis->company << endl;
	cout << "The diameter of the pizza: " 
		 << analysis->diameter << " centimeters" << endl;
	cout << "The weight of the pizza: " 
		 << analysis->weight << " grams" << endl;
	
	delete analysis;

	return 0; 
}