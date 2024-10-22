#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <thread>
#include <mutex>
#include <cstring>
#include <numeric>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int sx, int sy, int ex, int ey, const vector<string>& maps)
{
	vector<vector<bool>> visited(101, vector<bool>(101, false));
	vector<vector<int>> arr(101, vector<int>(101, INF));

	arr[sx][sy] = 0;
	visited[sx][sy] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));

	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];

			if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size() || visited[nx][ny] == true || maps[nx][ny] == 'X')
				continue;

			arr[nx][ny] = min(arr[cx][cy] + 1, arr[nx][ny]);
			visited[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}

	if (arr[ex][ey] == INF)
		return -1;

	return arr[ex][ey];
}

int solution(vector<string> maps) {
	int answer = 0;

	pair<int, int> S;
	pair<int, int> E;
	pair<int, int> L;

	for(int i = 0; i < maps.size(); i++)
	{
		for(int j = 0; j < maps[0].size(); j++)
		{
			if (maps[i][j] == 'S')
				S = make_pair(i, j);

			else if (maps[i][j] == 'E')
				E = make_pair(i, j);

			else if (maps[i][j] == 'L')
				L = make_pair(i, j);
		}
	}

	int StoL = BFS(S.first, S.second, L.first, L.second, maps);
	if (StoL < 0)
		return -1;

	int LtoE = BFS(L.first, L.second, E.first, E.second, maps);
	if (LtoE < 0)
		return -1;



	return StoL + LtoE;
}