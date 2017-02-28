/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 9 - Parentheses Balance - UVa #673
Programming Techiques - Simpson
February 16, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int N;
	string line;
	stack<char> s;

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		s.empty();
		getline(cin, line);
		if (line.size() == 0)
			cout << "Yes\n";
		else if (line.size() % 2 == 1)
			cout << "No\n";
		else
		{
			for (int j = 0; j < line.size(); j++)
			{
				if (line[j] == '[' || line[j] == '(')
					s.push(line[j]);
				else if ((line[j] == ']' && !s.empty() && s.top() == '[') ||
						(line[j] == ')' && !s.empty() && s.top() == '('))
					s.pop();
			}
			if (s.empty())
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
	return 0;
}