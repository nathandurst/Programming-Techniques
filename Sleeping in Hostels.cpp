/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 27 - Sleeping in Hostels - UVa 13181
Programming Techiques - Simpson
April 26, 2017

*////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string line;
	int i, j, dist, cnt;
	while (!cin.eof())
	{
		cin >> line;		

		dist = 0; cnt = 0;
		for (i = 0; i < line.size(); i++)
		{
			j = i;
			if (line[i] == '.')
			{
				cnt = 0;
				while (line[i] == '.')
				{
					cnt++;
					i++;
				}
				cnt = cnt - 1;
				
			}
			if (j == 0 || (i == line.size()))
			{
				if (cnt >= dist)
					dist = cnt;
			}
			else
			{
				if (cnt/2 > dist)
					dist = cnt/2;
			}
		}

		cout << dist;
		if (!cin.eof())
			cout << '\n';		
	}

	return 0;
}