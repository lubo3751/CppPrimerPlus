/* ex.04.09.cpp
Do Programming Exercise 6, but instead of declaring an array 
of three CandyBar structures, use new to allocate the array 
dynamically.
*/

#include<iostream>
#include<cstring>

struct CandyBar
	{
		char brand[20];
		float weight;
		int calories;
	};

int main(void)
{
	using namespace std;

	CandyBar * candies = new CandyBar [3];
	
	strcpy(candies[0].brand, "KitKat");
	candies[0].weight = 4.5;
	candies->calories = 280;

	strcpy(candies[1].brand, "Mars");
	candies[1].weight = 5.5;
	candies[1].calories = 250;

	strcpy(candies[2].brand, "Bounty");
	candies[2].weight = 6.5;
	candies[2].calories = 300;
	
	cout << candies[0].brand << ", " 
		 <<  candies[0].weight << ", " 
		 << candies[0].calories << endl;

	cout << candies[1].brand << ", " 
		 <<  candies[1].weight << ", " 
		 << candies[1].calories << endl;

	cout << candies[2].brand << ", " 
		 <<  candies[2].weight << ", " 
		 << candies[2].calories << endl;

	delete [] candies;

	return 0;
}