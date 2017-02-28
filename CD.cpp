/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 11 - CD - UVa #11849
Programming Techiques - Simpson
February 27, 2017

Uses set STL container. Prints the number of shared
values between two sets of input.
*////////////////////////////////////////////////

#include <iostream>
#include <set>
using namespace std;

int main()
{

	int jack, jill, disk;

	cin >> jack >> jill;
	while (jack != 0 && jill != 0)
	{
		set<int> CDs;
		for (int i = 0; i < jack; i++)
		{
			cin >> disk;
			CDs.insert(disk);
		}

		for (int j = 0; j < jill; j++)
		{
			cin >> disk;
			CDs.insert(disk);
		}


		cout << (jack + jill) - CDs.size() << '\n';

		cin >> jack >> jill;
	}

	return 0;
}