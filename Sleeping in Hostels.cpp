//13181
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string line;
	vector<char> v;
	int i, j, bed, dist;
	while (!cin.eof())
	{
		cin >> line;
		cout << line << '\n';
		/*i = j = 0;
		while (j < line.size())
		{
			while (line[i] != 'X' && i != line.size())
			{
				i++;
			}
			j = i;
			i++;
			if (j != line.size())
				cout << j << '\n';
		}*/

		v.resize(line.size() + 1);
		for (i = 1; i < v.size(); i++)
		{
			v[i] = line[i - 1];
			cout << v[i];
		}
		cout << '\n';
		bed = 1;// dist = 0;
		for (i = 1; i < v.size(); i++)
		{
			dist = 0;
			if (v[i] == 'X')
			{
				cout << i << '\n';
				if (i - bed > dist)
				{
					dist = i - bed;
					bed = i;
					cout << dist - 1 << '\n';
				}
			}
		}
	}

	return 0;
}
