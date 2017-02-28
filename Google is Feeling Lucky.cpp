/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 1 - Google is Feeling Lucky - UVa #12015
Programming Techiques - Simpson
January 19, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	int cases, i, j, max, num, size;
	vector<string> urls;
	string url;

	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		max = 0; urls.clear();
		for (j = 0; j < 10; j++)
		{
			cin >> url >> num;
			if (num > max)
			{
				max = num;
				urls.clear();
				urls.push_back(url);
			}
			else if (num == max)
				urls.push_back(url);
			
		}
		
		cout << "Case #" << i + 1 << ":\n";
		
		size = urls.size();
		for (j = 0; j < size; j++)
			cout << urls[j] << '\n';
	}
	return 0;
}

