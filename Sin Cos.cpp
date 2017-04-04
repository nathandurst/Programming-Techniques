/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 20 - Sin Cos - UVa #12575
Programming Techiques - Simpson
March 28, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14159265
using namespace std;

int main()
{
	int test;
	double A, B, min, max;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> A >> B;
		min = atan2(A, B); //inverse tan (minimum if positive)
		max = sqrt(pow(A, 2) + pow(B, 2)); //
		if (min < 0)
			min = min + (PI * 2);//inverse tan + PI * 2 (minimum if negative
		cout << fixed << setprecision(2) << min << ' ' << max << '\n';
	}

	return 0;
}