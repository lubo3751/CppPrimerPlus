/* ex.06.07.cpp
Write a program that reads input a word at a time until a lone q is entered.The
program should then report the number of words that began with vowels, the number
that began with consonants, and the number that fit neither of those categories.
One approach is to use isalpha() to discriminate between words beginning with
letters and those that don’t and then use an if or switch statement to further identify
those passing the isalpha() test that begin with vowels.A sample run might
look like this:
Enter words (q to quit):
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 others
*/

#include <iostream>
#include <cctype> 
#include <string>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    // ask the user for text input
    cout << "Enter words (q to quit):" << endl;
    int vowels = 0;      // counter
    int consonants = 0;  // counter
    int others = 0;      // counter
    std::string word;         // word holder

    cin >> word;
    while (word != "q" && word != "Q")
    {
        if (isalpha(word[0])) {
            switch(word[0])
            {
                case 'A':
                case 'a': 
                case 'E':
                case 'e': 
                case 'I':
                case 'i': 
                case 'O':
                case 'o': 
                case 'U':
                case 'u': 
                case 'Y':
                case 'y': ++vowels;      // count vowels
                    break;
                default : ++consonants;  // count consonants
            }
        } else {
            ++others;                    // count others
	}
        cin >> word;
    }
    // display results
    cout << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " others" << endl;
	 
    return 0;
}
