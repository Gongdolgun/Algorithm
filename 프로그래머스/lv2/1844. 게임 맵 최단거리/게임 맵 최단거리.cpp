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

bool check[101][101];
int num[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;

	check[0][0] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	num[0][0] = 1;

	int nx, ny, curr_x, curr_y;

	while(1)
	{
		if (q.empty())
			break;

		curr_x = q.front().first;
		curr_y = q.front().second;

		q.pop();

		for(int i = 0; i < 4; i++)
		{
			nx = curr_x + dx[i];
			ny = curr_y + dy[i];

			if(nx < 0 || nx >= maps[0].size() || ny < 0 || ny >= maps.size())		// 범위 벗어나면 continue;
				continue;

			if(check[ny][nx] == true)												// 이미 다녀온 곳이면 continue;
				continue;

			if(maps[ny][nx] == 0)													// maps가 닫혀있으면 continue;
				continue;

			q.push(make_pair(nx, ny));

			check[ny][nx] = true;
			num[ny][nx] = num[curr_y][curr_x] + 1;
		}
	}

	if (num[maps.size()-1][maps[0].size()-1] != 0)
		answer = num[maps.size()-1][maps[0].size()-1];

	else
		answer = -1;

	cout << answer;

    return answer;
}