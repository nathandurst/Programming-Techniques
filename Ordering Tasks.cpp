/*////////////////////////////////////////////////
Nathan Durst	:	nathandurst
Project 25 - Ordering Tasks - UVa #10305
Programming Techiques - Simpson
April 20, 2017
*////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;
vector<int> f;

void DFS(int v, vector<int> g1[], int a[])
{
	if (a[v] == 1) return;
	a[v] = 1;

	for (int i : g1[v])
	{
		if (a[i] != 2)
			DFS(i, g1, a);
	}
	a[v] = 2;
	f.push_back(v);
}

int main()
{

	int N, M, a, b;

	while (cin >> N >> M)
	{
		if (N == 0 && M == 0)
			break;

		vector<int> g[MAX];
		f.clear();
		int v[MAX] = { 0 };
		bool adj[MAX] = { false };

		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			g[a].push_back(b);
			adj[b] = true;
		}

		for (int i = 0; i <= N; i++)
		{
			if (!adj[i])
				DFS(i, g, v);
		}

		for (int i = f.size() - 1; i > 0; i--)
			cout << f[i] << ' ';
		cout << '\n';

	}

	return 0;
}
