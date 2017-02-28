/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 2 - Jolly Jumpers - UVa #10038
Programming Techiques - Simpson
January 19, 2017

*////////////////////////////////////////////////

#include <iostream>
using namespace std;


int main()
{
	int n, prev, curr, diff, i;
	bool jolly;

	while (!cin.eof())
	{
		int Numbers[3001] = { 0 };
		cin >> n;
		cin >> prev;
		for (i = 0; i < n - 1; i++)
		{
			cin >> curr;
			diff = abs(curr - prev);
			if (diff >= 1 && diff <= n - 1)
				Numbers[diff] = 1;
			prev = curr;
		}

		jolly = true;
		for (i = 1; i < n; i++)
		{
			if (!Numbers[i])
				jolly = false;
		}

		if (jolly)
			cout << "Jolly";
		else
			cout << "Not jolly";
		cout << endl;
	}

	return 0;
}