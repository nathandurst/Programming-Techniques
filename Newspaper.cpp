/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 5 - Newspaper - UVa 11340
Programming Techiques - Simpson
January 26, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int test, keysize, linesize, value, i, j, k, l;
	double total;
	string line;
	char character;
	map<char, int> key;
	ios_base::sync_with_stdio(false);


	cin >> test;
	for (i = 0; i < test; i++)
	{
		key.clear();
		total = 0;

		//reads character values
		cin >> keysize;
		for (j = 0; j < keysize; j++)
		{
			cin >> character >> value;
			key[character] = value;
		}
		//reads paragraph
		cin >> linesize;
		getchar();
		for (j = 0; j < linesize; j++)
		{
			getline(cin, line);
			for (k = 0; k < line.size(); k++)
			{
				if (key[line[k]])
				{
					total += key[line[k]];
				}
			}
		}

		total /= 100;
		cout << total << "$\n";
	}

	return 0;
}