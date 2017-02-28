/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 5 - Palindromes - UVa 401
Programming Techiques - Simpson
January 26, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int main()
{
	string word;
	bool palindrome; bool mirror;
	int size, i;
	stack<char> s;
	map<char, char> m;
	m['A'] = 'A'; m['E'] = '3'; m['H'] = 'H';
	m['I'] = 'I'; m['J'] = 'L'; m['L'] = 'J';
	m['M'] = 'M'; m['O'] = 'O'; m['S'] = '2';
	m['T'] = 'T'; m['U'] = 'U'; m['V'] = 'V';
	m['W'] = 'W'; m['X'] = 'X'; m['Y'] = 'Y';
	m['Z'] = '5'; m['1'] = '1'; m['2'] = 'S'; 
	m['3'] = 'E'; m['5'] = 'Z'; m['8'] = '8';
	while (getline(cin, word))
	{
		size = word.size();
		palindrome = true; mirror = true;

		for (i = 0; i < size; i++)
		{
			s.push(word[i]);
		}

		for (i = 0; i < size; i++)
		{
			if (s.top() != word[i])
				palindrome = false;
			if (m[s.top()] != word[i])
				mirror = false;
			s.pop();
		}

		cout << word;
		if (palindrome && mirror)
			cout << " -- is a mirrored palindrome.\n\n";
		else if (palindrome && !mirror)
			cout << " -- is a regular palindrome.\n\n";
		else if (!palindrome && mirror)
			cout << " -- is a mirrored string.\n\n";
		else
			cout << " -- is not a palindrome.\n\n";
		s.empty();


	}

	
	
	return 0;
}