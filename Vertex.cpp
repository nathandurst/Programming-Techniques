/*////////////////////////////////////////////////
Nathan Durst	:	nadurst0303
Project 23 - Vertex - UVa #280
Programming Techiques - Simpson
April 3, 2017
*////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int size, v, i, j, k, checksize;
	while (!cin.eof())
	{
		cin >> size;
		vector<vector<int>> graph(size + 1);

		cin >> i;
		while (i != 0)
		{
			cin >> v;
			while (v != 0)
			{
				graph[i].push_back(v);
				cin >> v;
			}
			cin >> i;
		}

		cin >> checksize;
		while (checksize != 0)
		{
			cin >> v;
			vector<int> inaccessible(graph[v].size());
			int isize = 0;
			for (i = 0; i < graph[v].size(); i++)
			{
				for (k = 1; k < size + 1; k++)
				{
					if (graph[v][i] != k)
					{
						cout << v << " does not connect to " << k << '\n';
						inaccessible.push_back(k);
						isize++;
					}
				}

			}
			//inaccessible.resize(isize);
			cout << inaccessible.size() << " ";
			for (i = 0; i < isize; i++)
			{
				cout << inaccessible[i] << " ";
			}
			cout << '\n';
			checksize--;
		}
		
	}
}
