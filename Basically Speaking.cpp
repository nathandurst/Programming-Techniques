/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 19 - Basically Speaking - UVa #389
Programming Techiques - Simpson
March 27, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;

int horner(vector<int> v, int base)
{
	int s = v[0];
	for (int i = 1; i < v.size(); i++)
		s = s*base + v[i];
	return s;
}


int main()
{
	map<char, int> m;
	map<int, char> n;
	string number;
	int base1, base2, decimal;
	m['A'] = 10; m['B'] = 11; m['C'] = 12;
	m['D'] = 13; m['E'] = 14; m['F'] = 15;
	n[10] = 'A'; n[11] = 'B'; n[12] = 'C';
	n[13] = 'D'; n[14] = 'E'; n[15] = 'F';

	while (cin >> number >> base1 >> base2)
	{
		int size = number.size();
		vector<int> first(size);
		stack<int> second;
		string result = "";
		for (int i = 0; i < number.size(); i ++)
		{
			if (number[i] == 'A' || number[i] == 'B' ||
				number[i] == 'C' || number[i] == 'D' ||
				number[i] == 'E' || number[i] == 'F')
				first[i] = m[number[i]];
			else
				first[i] = number[i] - '0';
		}

		decimal = horner(first, base1);

		if (base2 == 10 || decimal == 0)
			result = to_string(decimal);
		else
		{
			while (decimal > 0)
			{
				second.push(decimal % base2);
				decimal = decimal / base2;
			}
			int size = second.size();
			if (size > 7)
				result = "ERROR";
			else
			{
				for (int i = 0; i < size; i++)
				{
					if (second.top() > 9)
						result = result + n[second.top()];
					else
						result = result + to_string(second.top());
					second.pop();
				}
			}
		}	
		cout << right << setw(7) << result << '\n';
	}
	
	return 0;
}