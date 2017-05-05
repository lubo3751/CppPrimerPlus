/* ex.05.08.cpp
Write a program that uses an array of char and a loop to read 
one word at a time until the word done is entered.The program 
should then report the number of words entered (not counting 
done). A sample run could look like this: 

Enter words (to stop, type the word done):
anteater birthday category dumpster
envy finagle geometry done for sure
You entered a total of 7 words.

You should include the cstring header file and use the strcmp() 
function to make the comparison test.
*/

#include <iostream>
#include <cstring>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
	
    cout << "Enter words (to stop, type the word done):" << endl;
    char word[20];
    cin >> word;

    int count = 0;
    while(strcmp(word, "done"))
    {
        ++count;
        cin >> word;
    }

    cout << "You entered a total of " << count << " words." << endl;	

    return 0;
}
