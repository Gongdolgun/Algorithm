#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };	// 좌, 우
int dy[4] = { 0, 1, 0, -1 };	// 상, 하

// 1. 같은 크기의 갔다 온 곳인지 체크하는 공간 필요
// 2. 범위 설정 ( 행이 0보다 작거나, maps[0].size()와 크거나 같거나, 열이 0보다 작거나, map.size()보다 크거나 같거나
// 3. 이전의 값 누적

int n, m;
bool isbreak = true;
vector<vector<int>> vec;

queue<pair<int, int>> q;

bool check[1001][1001];
int num[1001][1001];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < n; j++)
		{
			int itmp;
			cin >> itmp;
			tmp.push_back(itmp);
		}
		vec.push_back(tmp);
	}
}

void findOne(vector<vector<int>> &maps)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n ;j++)
		{
			if (maps[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
}

void solution(vector<vector<int> > maps)
{
	int answer = 0;
	int maxInt = 0;
	int nx, ny, curr_x, curr_y;

	findOne(maps);

	while (1)
	{
		if (q.empty())
		{
			break;
		}

		curr_x = q.front().first;
		curr_y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = curr_x + dx[i];
			ny = curr_y + dy[i];

			if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size())		// 범위 벗어나면 continue;
				continue;

			if (check[nx][ny] == true)												// 이미 다녀온 곳이면 continue;
				continue;

			if (maps[nx][ny] == 1 || maps[nx][ny] == -1)							// maps가 닫혀있으면 continue;
				continue;

			q.push(make_pair(nx, ny));

			check[nx][ny] = true;
			num[nx][ny] = num[curr_x][curr_y] + 1;

			maxInt = max(num[nx][ny], num[curr_x][curr_y] + 1);
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(maps[i][j] == 1)
				continue;

			if(maps[i][j] == 0 && check[i][j] == false)
			{
				cout << -1;
				return;
			}
		}
	}

	cout << maxInt;
}

int main()
{
	input();
	solution(vec);

	return 0;
}