/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 20 - Area - UVa #10589
Programming Techiques - Simpson
March 28, 2017

*////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float dist(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int main()
{
	int N, M;
	double a, x, y, result;
	cin >> N >> a;
	while (N != 0)
	{
		M = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y;
			if ((dist(0, 0, x, y) <= a) && (dist(0, a, x, y) <= a)
				&& (dist(a, 0, x, y) <= a) && (dist(a, a, x, y) <= a))
				M++;
		}
		result = M*a*a/N;
		cout << fixed << setprecision(5) << result << '\n';
		cin >> N >> a;

	}
	return 0;
}