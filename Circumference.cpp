/*////////////////////////////////////////////////
Nathan Durst	:	nadurst0303
Project 20 - Circumference - UVa #438
Programming Techiques - Simpson
April 3, 2017
*////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.141592653589793239
using namespace std;

float dist(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double a, b, c;
	double perimeter, semi, area, radius;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		a = dist(x1, y1, x2, y2);
		b = dist(x2, y2, x3, y3);
		c = dist(x3, y3, x1, y1);

		perimeter = a + b + c;
		semi = perimeter / 2;
		area = sqrt(semi * (semi - a) * (semi - b) * (semi - c));
		radius = (a*b*c) / (4 * area);
		cout << fixed << setprecision(2) << 2 * PI*radius << '\n';

	}

	return 0;
}
