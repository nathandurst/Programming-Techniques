/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 11 - Splitting Numbers - UVa #11933
Programming Techiques - Simpson
February 21, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	bitset<32> bs, a, b;
	int number, i, j;

	while (cin >> number)
	{
		if (number == 0)
			break;
		else
		{
			bs = number;
			i = 0; j = 1;
			while (!bs.none())
			{
				if (bs[0])
				{
					if (j % 2 == 0)
						a.set(i);
					else
						b.set(i);
					j++;
				}
				bs >>= 1;
				i++;
			}
			cout << a.to_ulong() << ' ' << b.to_ulong() << '\n';
			a.reset(); b.reset();
		}
	}


	return 0;
}