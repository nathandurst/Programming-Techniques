/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 18 - Big Mod - UVa #374
Programming Techiques - Simpson
March 23, 2017

*////////////////////////////////////////////////

//USING MODULAR EXPONENTIATION

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int R, B, P, M;
	while (cin >> B >> P >> M)
	{
		//Binary Method (Right-to-Left)
		R = 1;
		B = B % M;
		while (P > 0)
		{
			if (P % 2 == 1)
				R = (R * B) % M;
			P = P >> 1;
			B = (B * B) % M;
		}
		
		cout << R << '\n';
	}
	return 0;
}