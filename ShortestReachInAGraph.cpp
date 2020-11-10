#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

class Graph {
public:
	Graph(int n) {
		this->vertices = n;
		adj = new list<int>[vertices];
	}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> shortest_reach(int start) {
		vector<int> distances(vertices, -1);

		bool visited[vertices];
		for (int i = 0; i<vertices; i++)
		{
			visited[i] = false;
		}

		list<int> q;

		q.push_back(start);

		visited[start] = true;
		distances[start] = 0;


		list<int>::iterator it;

		while (!q.empty())
		{
			start = q.front();
			q.pop_front();
			for (it = adj[start].begin(); it != adj[start].end(); ++it)
			{
				if (!visited[*it] && distances[*it] == -1)
				{
					q.push_back(*it);
					distances[*it] = distances[start] + 6;
					visited[*it] = true;
				}
			}
		}
		return distances;
	}
private:
	int vertices;
	list<int>*adj;
};

int main() {
	int queries;
	cin >> queries;

	for (int t = 0; t < queries; t++) {

		int n, m;
		cin >> n;
		// Create a graph of size n where each edge weight is 6: 
		Graph graph(n);
		cin >> m;
		// read and set edges
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			// add each edge to the graph
			graph.add_edge(u, v);
		}
		int startId;
		cin >> startId;
		startId--;
		// Find shortest reach from node s
		vector<int> distances = graph.shortest_reach(startId);

		for (int i = 0; i < distances.size(); i++) {
			if (i != startId) {
				cout << distances[i] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}