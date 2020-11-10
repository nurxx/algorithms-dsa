#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

pair<long long, pair<int, int>>p[500000];
int id[500000];
int vertices, edges;

int getRoot(int x)
{

	while (id[x] != x)
	{
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void bound(int u, int v)
{
	int p = getRoot(u);
	int q = getRoot(v);
	id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int>> p[])
{
	int sum, minSum = 0;
	for (int i = 0; i<edges; i++)
	{
		int u = p[i].second.first;
		int v = p[i].second.second;

		sum = p[i].first;

		if (getRoot(u) != getRoot(v))
		{
			minSum += sum;
			bound(u, v);
		}
	}
	return minSum;
}
int main()
{
	for (int i = 0; i<500000; i++)
	{
		id[i] = i;
	}
	cin >> vertices >> edges;
	for (int i = 0; i<edges; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		p[i] = make_pair(w, make_pair(u, v));
	}
	sort(p, p + edges);
	long long mst = kruskal(p);
	cout << mst;
	return 0;
}