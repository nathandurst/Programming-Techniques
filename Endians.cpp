/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 10 - Endians - UVa #594
Programming Techiques - Simpson
February 21, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
	bitset<32> forward, reverse;
	int number;

	while (cin >> number)
	{
		forward = number;

		for (int i = 1; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				reverse[31 - ((i - 1) * 8) - j] = forward[(i * 8) - 1 - j];
			}
		}

		cout << number << " converts to " << reverse.to_ulong() << '\n';
	}

	return 0;
}