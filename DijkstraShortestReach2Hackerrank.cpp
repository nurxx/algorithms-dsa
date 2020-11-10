#include <iostream>
#include <climits>

using namespace std;

int matrix[5000][5000];
int distances[5000];
bool visited[5000];

int find(int vertices)
{
	int min = INT_MAX;
	int nextNode = 0;
	for (int j = 1; j <= vertices; j++)
	{
		if (min>distances[j] && !visited[j] && distances[j] != -1)
		{
			min = distances[j];
			nextNode = j;
		}
	}
	return nextNode;
}
void shortestPath(int s, int vertices)
{
	for (int j = 1; j <= vertices; j++)
	{
		visited[j] = false;
		distances[j] = -1;
	}

	distances[s] = 0;
	visited[s] = true;

	int min;
	int nextNode;

	for (int i = 0; i<vertices; i++)
	{
		nextNode = find(vertices);

		visited[nextNode] = true;

		for (int k = 1; k <= vertices; k++)
		{
			if (matrix[nextNode][k]>0)
			{
				if (distances[k] > distances[nextNode] + matrix[nextNode][k] || distances[k] == -1)
				{
					distances[k] = distances[nextNode] + matrix[nextNode][k];
				}
			}
		}
	}

	for (int i = 1; i <= vertices; i++)
	{
		if (i != s)cout << distances[i] << ' ';
	}
	cout << endl;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	short t;
	cin >> t;
	int vertices, edges;

	for (int i = 1; i <= t; i++)
	{
		cin >> vertices >> edges;
		for (int rows = 1; rows <= vertices; rows++)
		{
			for (int cols = 1; cols <= vertices; cols++)
			{
				matrix[rows][cols] = 0;
			}
		}
		for (int k = 1; k <= edges; k++)
		{
			int u, v, w;
			cin >> u, v, w;

			if (matrix[u][v]>0 && w<matrix[u][v])
			{
				matrix[u][v] = w;
				matrix[v][u] = w;
			}
			matrix[u][v] = w;
			matrix[v][u] = w;
		}
		int s;
		cin >> s;
		shortestPath(s, vertices);
	}
	return 0;
}