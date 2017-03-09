/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 15 - Conformity - UVa #11286
Programming Techiques - Simpson
March 7, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int lines, course, max, popularity;
	cin >> lines;
	while (lines != 0)
	{
		max = 0; popularity = 0;
		map<vector<int>, int> m;
		while (lines--)
		{
			vector<int> v(5);
			for (int i = 0; i < 5; i++)
			{
				cin >> course;
				v[i] = course;
			}
			sort(v.begin(), v.end());

			if (m.find(v) == m.end())
				m[v] = 1;
			else
				m[v]++;

			if (m[v] > max)
				max = m[v];
		}

		for (map<vector<int>, int > ::iterator it = m.begin(); it != m.end(); it++)
		{
			if (it->second == max)
				popularity = popularity + max;
		}

		cout << popularity << '\n';


		cin >> lines;
	}
	return 0;
}