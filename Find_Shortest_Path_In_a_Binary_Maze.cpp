

/*Sample Input 0

5 5 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 0
0 0 0 0 0
4 0
4 4
Sample Output 0

12
8*/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 5000
struct Node {
	int x;
	int y;
	int dist;
};
int row[] = { -1,0,0,1 };
int col[] = { 0,-1,1,0 };

bool isSafe(int **arr, bool visited[5000][5000], int row, int col, int m, int n)
{
	return ((row >= 0) && (row < m) && (col >= 0) && (col < n) && (arr[row][col] == 0) && !visited[row][col]);
}
int shortestPathInABinaryMaze(int **arr, bool visited[5000][5000], int x, int y, int m, int n)
{
	queue<Node> q;

	visited[0][0] = true;
	q.push({ 0,0,0 });
	int minDist = INT_MAX;

	while (!q.empty())
	{
		Node node = q.front();

		q.pop();

		int i = node.x, j = node.y, dist = node.dist;
		if (i == x && j == y)
		{
			minDist = dist;
			break;
		}
		for (int k = 0; k < 4; k++)
		{
			if (isSafe(arr, visited, i + row[k], j + col[k], m, n))
			{
				visited[i + row[k]][j + col[k]] = true;
				q.push({ i + row[k], j + col[k],dist + 1 });
			}
		}
	}
	if (minDist != INT_MAX)
	{
		return minDist;
	}

	return -1;
}
int main()
{
	int m, n, k;
	cin >> m >> n >> k;

	int** arr = new int*[n];
	for (int i = 0; i < m; i++)
		arr[i] = new int[n];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int x, y;
	for (int i = 0; i < k; i++)
	{
		bool visited[5000][5000] = { false };
		cin >> x >> y;
		cout << shortestPathInABinaryMaze(arr, visited, x, y, m, n) << endl;
	}

	for (int i = 0; i<m; i++)
	{
		delete[] arr[i];
	}
	delete arr;
	return 0;
}