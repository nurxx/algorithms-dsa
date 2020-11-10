#include <iostream>
#include <algorithm>
using namespace std;

int vertices, edges;
int p[3000];

struct Edge {
	int from;
	int to;
	long long weight;
};
bool comparator(Edge e1, Edge e2)
{
	return e1.weight<e2.weight;
}
int getRoot(int node)
{
	if (node == p[node])return node;
	else return p[node] = getRoot(p[node]);
}
int main()
{
	Edge edg[500000];

	cin >> vertices >> edges;
	for (int i = 0; i<edges; i++)
	{
		cin >> edg[i].from >> edg[i].to >> edg[i].weight;
	}
	sort(edg, edg + edges, comparator);
	int s;
	cin >> s;

	for (int i = 0; i<vertices; i++)
	{
		p[i] = i;
	}
	long long sum = 0;
	for (int i = 0; i<vertices; i++)
	{
		int root1 = getRoot(edg[i].from);
		int root2 = getRoot(edg[i].to);

		if (root1 != root2)
		{
			int sw = rand() % 2;
			if (sw == 0) p[root1] = root2;
			else p[root2] = root1;

			sum += edg[i].weight;
		}
	}

	cout << sum << endl;
	return 0;
}
