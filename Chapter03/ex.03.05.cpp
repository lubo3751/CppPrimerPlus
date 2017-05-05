/* ex.03.05.cpp
Write a program that requests the user to enter the current world 
population and the current population of the U.S. (or of some 
other nation of your choice). Store the information in variables 
of type long long. Have the program display the percent that the 
U.S. (or other nation’s) population is of the world’s population. 
The output should look something like this:

Enter the world's population: 6898758899
Enter the population of the US: 310783781

The population of the US is 4.50492% of the world population.
You can use the Internet to get more recent figures.
*/

#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter the world's population: ";
    long long world_population;
    cin >> world_population;	
    cout << "Enter the population of the US: ";
    long long us_population;
    cin >> us_population;

    double percentage = double(us_population) / (double(world_population) / 100.0);

    cout << "The population of the US is " << percentage;
    cout << "% of the world population." << endl;

    return 0; 
}
