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

int BFS(int v)
{

}

int main()
{
	int size, v, i, front, checksize, isize;
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
			v = size - BFS(v);




			isize = Q.size();
			cout << isize << " ";
			for (i = 0; i < isize; i++)
			{
				cout << Q.front() << " ";
				Q.pop();
			}
			cout << '\n';
			checksize--;
		}
		cin >> size;
		
	}
}
