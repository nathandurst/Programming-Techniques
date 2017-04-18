/*////////////////////////////////////////////////
Nathan Durst	:	nadurst0303
Project 23 - Vertex - UVa #280
Programming Techiques - Simpson
April 3, 2017
*////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool accessible[100];

int main()
{
	int size, v, w, i, front, top, checksize, isize;
	cin >> size;
	while (size != 0)
	{
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
			bool accessible[100] = { false };
			queue<int> Q;
			Q.push(v); w = 0;
			while (!Q.empty())
			{
				top = Q.front();
				Q.pop();
				for (i = 0; i < graph[top].size(); i++)
				{
					v = graph[top][i];
					if (!accessible[v])
					{
						w++;
						accessible[v] = true;
						Q.push(v);
					}
				}
			}
			w = size - w;
			cout << v;
			if (v != 0)
				for (i = 1; i < size; i++)
				{
					if (!accessible[i])
						cout << " " << i;
				}			
			cout << '\n';
			checksize--;
		}
		cin >> size;

	}
}
