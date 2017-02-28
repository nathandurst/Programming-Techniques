/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 0 - Relation Operator - UVa #11172
Programming Techiques - Simpson
January 19, 2017

*////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{

	int problems;
	int i, a, b;

	cin >> problems;
	for (i = 0; i < problems; i++)
	{
		cin >> a >> b;
		if (a > b)
			cout << '>' << endl;
		else if (a < b)
			cout << '<' << endl;
		else
			cout << '=' << endl;
	}
	return 0;
}