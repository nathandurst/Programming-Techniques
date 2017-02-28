/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 8 - Rails - UVa #514
Programming Techiques - Simpson
February 15, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <stack>
using namespace std;

int cars, c, i, j;
stack<int>train;


void check()
{
	while (!cin.eof())
	{
		while (train.size() > 0)
			train.pop();

		j = 0;
		for (i = 0; i < cars; i++)
		{
			cin >> c;
			if (c == 0)
				return;
			while (j != c && j < cars)
			{
				if (train.size() > 0 && train.top() == c )
					break;
				j++;
				train.push(j);
			}
			if (train.top() == c)
				train.pop();
		}
		if (train.size() == 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

int main()
{
	while (1)
	{
		cin >> cars;
		if (cars == 0)
			break;

		check();
		cout << '\n';
	}
	return 0;
}


