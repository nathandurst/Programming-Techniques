/*////////////////////////////////////////////////
Nathan Durst	:	nadurst0303
Project 24 - Sending Email - UVa #10986
Programming Techiques - Simpson
April 17, 2017
*////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> p;
map<p, int> dist;
queue<int> q;

int main()
{
	int C, n, m, S, T, a, b, c;
	cin >> C;
	for (int i = 1; i <= C; i++)
	{
		cin >> n >> m >> S >> T;
		dist.clear();
		vector<int> v[50000];
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b >> c;
			dist[make_pair(a, b)] = dist[make_pair(b, a)] = c;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int x[20005];
		for (int j = 0; j < n; j++)
			x[j] = 1e9;
		x[S] = 0;
		q.empty();
		q.push(S);
		while (!q.empty())
		{
			a = q.front();
			q.pop();
			for (int k = 0; k < v[a].size(); k++)
			{
				b = v[a][k];
				if (dist.count(make_pair(a, b)))
				{
					c = dist[make_pair(a, b)];
					if (x[a] + c < x[b])
					{
						x[b] = x[a] + c;
						q.push(b);
					}
				}
			}
		}
		cout << "Case #" << i << ": ";
		if (x[T] != 1e9)
			cout << x[T] << '\n';
		else
			cout << "unreachable\n";
	}
	return 0;
}