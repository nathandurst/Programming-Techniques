/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 16 - Hardwood Species - UVa #11388
Programming Techiques - Simpson
March 7, 2017

*////////////////////////////////////////////////

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int main()
{
	long T, G, L, a, b;

	cin >> T;
	while (T--)
	{
		cin >> G >> L;
		a = GCD(G, L);
		b = (G * L) / GCD(G, L);
		if (a == G && b == L)
			cout << a << ' ' << b;
		else
			cout << "-1";
		cout << '\n';
	}

	return 0;
}