#include <bits/stdc++.h>
using namespace std;

class Graph {

	int V;
	list<int>*adj;
public:

	Graph(int v) {
		this->V = v;
		adj = new list<int>[2 * V + 1];
	}

	void addEdge(int v, int w) {
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	int DFS(int v, bool visited[]) {
		int components = 1;
		visited[v] = true;
		list<int>::iterator it;
		for (it = adj[v].begin(); it != adj[v].end(); ++it)
		{
			if (!visited[*it])
			{
				components += DFS(*it, visited);
			}
		}
		return components;
	}

};
int main()
{
	int v;
	cin >> v;
	bool visited[2 * v + 1];
	memset(visited, false, 2 * v + 1);

	Graph g(v);

	int v1, v2;
	int minimum = INT_MAX;
	int maximum = INT_MIN;
	int components;
	for (int i = 1; i <= v; i++)
	{
		cin >> v1 >> v2;
		g.addEdge(v1, v2);
	}
	for (int i = 1; i <= v; i++)
	{
		if (!visited[i])
		{
			components = g.DFS(i, visited);
			if (components>1)
			{
				maximum = max(maximum, components);
				minimum = min(minimum, components);
			}
		}
	}
	printf("%d %d", minimum, maximum);
	return 0;
}