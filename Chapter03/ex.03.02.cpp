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

const double INCH_TO_M = 0.0254;
const double LB_TO_KG = 2.2;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter your height in feet, and inches." << endl;	
    cout << "First, enter the feet: _\b";
    double feet;
    cin >> feet;
    cout << "Next, enter the inches: _\b";
    double inches;
    cin >> inches;
    cout << "Finally, enter your weithg in pounds: ___\b\b\b";
    double pounds;
    cin >> pounds;

    inches = inches + (feet * 12.0);
    double meters = inches * INCH_TO_M;
    double mass = pounds / LB_TO_KG;

    double bmi = mass / (meters * meters);
    cout << "Your BMI is " << bmi << "." << endl;

    return 0; 
}
