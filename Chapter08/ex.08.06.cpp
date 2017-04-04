/* ex.08.06
Write a template function maxn() that takes as its arguments an array of items of
type T and an integer representing the number of elements in the array and that
returns the largest item in the array.Test it in a program that uses the function template
with an array of six int value and an array of four double values.The program
should also include a specialization that takes an array of pointers-to-char as
an argument and the number of pointers as a second argument and that returns the
address of the longest string. If multiple strings are tied for having the longest
length, the function should return the address of the first one tied for longest.Test
the specialization with an array of five string pointers.
*/

#include <iostream>
#include <cstring>

template <typename T> 
T maxn(T ar[], int);

template <>
char * maxn<char *>(char * ar[], int);

int main()
{
	using namespace std;

	int iNums[6] = {4, 6, 2, 8, 1, 7};
	cout << maxn(iNums, 6) << endl;

	double dNums[4] = {3.5, 6.3, 9.8, 1.3};
	cout << maxn(dNums, 4) << endl;

	char * pStr[] = {
		"bla bla", 
		"bla", 
		"bla bla bla", // 11 characters
		"What's up??", // 11 characters
		"I see"
	}; 
	cout << maxn(pStr, 5) << endl;

	return 0;
}

template <typename T>
T maxn(T ar[], int size)
{
	T max = ar[0];
	for (int i = 1; i < size; ++i)
		if (max < ar[i])
			max = ar[i];
	return max;
}

template <> 
char * maxn<char *>(char * ar[], int size)
{
	char * longest = ar[0];
	for (int i = 1; i < size; ++i)
		if (strlen(longest) < strlen(ar[i]))
			longest = ar[i];
	return longest;
}