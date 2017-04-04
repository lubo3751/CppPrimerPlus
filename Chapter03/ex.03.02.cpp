/* ex.03.02.cpp
Write a short program that asks for your height in feet and 
inches and your weight in pounds. (Use three variables to store 
the information.) Have the program report your body mass index 
(BMI).To calculate the BMI, first convert your height in feet 
and inches to your height in inches (1 foot = 12 inches).Then 
convert your height in inches to your height in meters by 
multiplying by 0.0254.Then convert your weight in pounds into 
your mass in kilograms by dividing by 2.2. Finally, compute your 
BMI by dividing your mass in kilograms by the square of your 
height in meters. Use symbolic constants to represent the various 
conversion factors.
*/

#include <iostream>

float const InToM = 0.0254;
float const LbToKg = 2.2;

int main()
{  
	using namespace std;

	cout << "Enter your height in feet, and inches:" << endl;	
	cout << "First, enter the feet: _\b";
	float feet;
	cin >> feet;
	cout << "Next, enter the inches: _\b";
	float inches;
	cin >> inches;
	cout << "Finally, enter your weithg in pounds: ___\b\b\b";
	float pounds;
	cin >> pounds;

	inches = inches + (feet * 12.0);
	double meters = inches * InToM;
	double mass = pounds / LbToKg;

	double bmi = mass / (meters * meters);
	cout << "Your BMI is " << bmi << endl;
	
    return 0; 
}