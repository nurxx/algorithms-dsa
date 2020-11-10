#include <iostream>
#include <climits>
#include <algorithm>


using namespace std;
int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	int matrix[vertices + 1][vertices + 1];
	int distances[vertices + 1];
	bool visited[vertices + 1];
	for (int i = 0; i<vertices + 1; i++)
	{
		for (int j = 0; j<vertices + 1; j++)
		{
			matrix[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i<vertices + 1; i++)
	{
		distances[i] = INT_MAX;
		visited[i] = false;
	}
	for (int i = 0; i<edges; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (matrix[u][v]>w)
		{
			matrix[u][v] = w;
			matrix[v][u] = w;
		}
	}

	int start;
	cin >> start;

	distances[start] = 0;
	int sum = 0;
	int min, nextNode;
	while (1)
	{
		min = INT_MAX;
		nextNode = -1;

		for (int i = 1; i<vertices + 1; i++)
		{
			if (min>distances[i] && !visited[i])
			{
				min = distances[i];
				nextNode = i;

			}
		}
		if (nextNode == -1)break;

		visited[nextNode] = true;
		sum += distances[nextNode];

		for (int i = 1; i<vertices + 1; i++)
		{
			if (!visited[i])
			{
				if (matrix[nextNode][i] != INT_MAX && distances[i]>matrix[nextNode][i])
					distances[i] = matrix[nextNode][i];
			}
		}
	}
	cout << sum;

	return 0;
}
