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
		this->adj = new list<int>[vertices];
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
	}

	void DFS(int start)
	{
		vector<int>visited(vertices, false);

		stack<int> s;
		s.push(start);

		while (!s.empty())
		{
			start = s.top();
			cout << start << " ";
			s.pop();

			list<int>::iterator it;
			for (it = adj[start].begin(); it != adj[start].end(); ++it)
			{
				if (!visited[*it])
				{
					visited[start] = true;
					s.push(*it);
				}
			}
		}


	}
};
int main()
{
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 4);

	g.DFS(0);

	system("pause");
	return 0;
}