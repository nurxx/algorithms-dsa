#include <iostream>

using namespace std;

int main()
{
	int vertices;
	cin >> vertices;

	int **matrix = new int*[vertices];
	for (int i = 0; i < vertices; i++) {
		matrix[i] = new int[vertices];
	}
	int *distance = new int[vertices];
	bool *visited = new bool[vertices];
	int *preD = new int[vertices];

	int min;
	int nextNode = 0;

	printf("Enter the matrix :");

	for (int i = 0; i < vertices; i++)
	{
		visited[i] = false;
		preD[i] = 0;
		for (int j = 0; j < vertices; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 0)matrix[i][j] = INT_MAX;
		}
	}
	distance = matrix[0];
	distance[0] = 0;
	visited[0] = true;
	for (int i = 0; i < vertices; i++)
	{
		min = INT_MAX;
		for (int j = 0; j < vertices; j++)
		{
			if (min > distance[j] && !visited[j])
			{
				min = distance[j];
				nextNode = j;
			}
		}
		visited[nextNode] = true;

		for (int k = 0; k < vertices; k++)
		{
			if (!visited[k])
			{
				if (min + matrix[nextNode][k] < distance[k])
				{
					distance[k] = min + matrix[nextNode][k];
					preD[k] = nextNode;
				}
			}
		}
	}

	for (int i = 0; i < vertices; i++)
	{
		printf("%d | ", distance[i]);
	}
	for (int i = 0; i < vertices; i++) {
		
		int j;
		cout << "Path=  " << i;
		
		j = i;

		do {
			j = preD[j];
			cout << " <- " << j;
		} while (j != 0);
		
		cout << "\n";
	}

	system("pause");
	return 0;
}