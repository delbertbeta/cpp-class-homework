#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main()
{
	string text;
	cout << "Pleasse enter a text or a number: ";
	cin >> text;
	bool isPalindrome = true;

	string::iterator begin = text.begin();
	string::reverse_iterator reBegin = text.rbegin();

	while (begin != text.end())
	{
		if (*begin != *reBegin)
		{
			isPalindrome = false;
			break;
		}
		else
		{
			begin++;
			reBegin++;
		}
	}

	if (isPalindrome == true)
	{
		cout << "It's a palindrome." << endl;
	}
	else
	{
		cout << "It's not a palindrome." << endl;
	}

	return 0;
}
