/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 29 - Rotations - UVa #13193
Programming Techiques - Simpson
April 29, 2017

*////////////////////////////////////////////////
#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

int main()
{

	int test, index;
	long num;
	bool rotation;
	string binary;
	cin >> test;
	while (test--)
	{
		cin >> num;
		char binary[] = "00000000000000000000000000000000";
		vector<int> check(32);
		rotation = true;
		
		//convert number to a 32 bit binary
		for (int i = 31; i >= 0; --i)
		{
			if (num % 2)
				binary[i] = '1';
			num /= 2;
		}

		//calculates 5 consecutive bits for every case and marks and index vector
		for (int i = 0; i < 32; i++)
		{
			index = ((binary[i % 32] - '0') * 16) + ((binary[(i + 1) % 32] - '0') * 8) + ((binary[(i + 2) % 32] - '0') * 4) +
				((binary[(i + 3) % 32] - '0') * 2) + (binary[(i + 4) % 32] - '0');
			check[index] = 1;
		}

		//checks vector to see if every number from 0 - 31 is represented
		for (int i = 0; i < 32; i++)
		{
			if (check[i] == 0)
				rotation = false;
		}

		//print answer
		if (rotation == false)
			cout << "no\n";
		else
			cout << "yes\n";
	}
	return 0;
}