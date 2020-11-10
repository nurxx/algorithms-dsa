#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph {
	int vertices;
	list<int>*adj;
	
public:
	Graph(int v)
	{
		this->vertices = v;
		adj = new list<int>[vertices];
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
	}

	void BFS(int start)
	{
		vector<int> visited(vertices,false);
		
		list<int> q;
		q.push_back(start);

		visited[start] = true;

		while (!q.empty())
		{
			start = q.front();
			cout << start << " ";
			q.pop_front();

			list<int>::iterator it;

			for (it = adj[start].begin(); it != adj[start].end(); ++it)
			{
				if (!visited[*it])
				{
					visited[*it] = true;
					q.push_back(*it);
				}
			}
		}
		
	}

};
int main()
{
	int n;
	cin >> n;
	
	Graph g(n);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.BFS(2);

	system("pause");
	return 0;
}