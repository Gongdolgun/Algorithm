#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

vector<bool> visited;

void bfs_1(int n, int x, vector<vector<int>> computers)
{
	queue<int> q;

	q.push(x);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < n; i++)
		{
			if (x == i)
				continue;

			if (computers[x][i] == 1)
			{
				if (visited[x] == true && visited[i] == true)
					continue;

				visited[x] = true;
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	visited.resize(n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (computers[i][j] == 1 && visited[i] == false)
			{
				bfs_1(n, i, computers);
				answer++;
			}
		}
	}

	cout << answer;
	return answer;
}