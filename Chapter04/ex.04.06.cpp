/* ex.04.06.cpp
The CandyBar structure contains three members, as described in 
Programming Exercise 5.Write a program that creates an array of 
three CandyBar structures, initializes them to values of your 
choice, and then displays the contents of each structure.
*/

#include <iostream>

struct CandyBar
{
	char brand[20];
	float weight;
	int calories;
};

int main()
{
	using namespace std;

	CandyBar candies[3] =
	{
		{"KitKat", 4.5, 280},
		{"Mars", 5.5, 250},
		{"Bounty", 6.5, 300}
	};

	cout << candies[0].brand << ", " 
		 << candies[0].weight << ", " 
		 << candies[0].calories << endl;

	cout << candies[1].brand << ", " 
		 << candies[1].weight << ", " 
		 << candies[1].calories << endl;

	cout << candies[2].brand << ", " 
		 << candies[2].weight << ", " 
		 << candies[2].calories << endl;
	
	return 0; 
}