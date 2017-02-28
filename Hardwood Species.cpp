/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 11 - Hardwood Species - UVa #10226
Programming Techiques - Simpson
March 1, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	int cases, trees;
	string line;
	cin >> cases;
	cin.ignore();
	getline(cin, line);
	while (cases--)
	{
		map<string, int> m;
		trees = 0;
		getline(cin, line);
		while (line != "")
		{
			if (m.find(line) == m.end())
				m[line] = 1;
			else
				m[line]++;
			trees++;

			getline(cin, line);
		}

		for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
		{ 
			cout << it->first << " " << fixed << setprecision(4) 
				<< (float)it->second / (float)trees * 100 << '\n';
		}
		cout << '\n';

	}
	return 0;
}