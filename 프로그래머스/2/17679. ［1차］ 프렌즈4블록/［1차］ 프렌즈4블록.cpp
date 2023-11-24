#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

int m, n;

int xpos[4] = { 0, 1, 0, -1 };
int ypos[4] = { 1, 0, -1, 0 };
int blocks[31][31];

bool check[31][31];

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			blocks[i][j] = (board[i][j] - 'A') + 1;

	queue<pair<int, int>> q;

	while (1)
	{
		for (int i = 0; i < m - 1; i++) {										// 블록인 부분 추출
			for (int j = 0; j < n - 1; j++) {
				if (blocks[i][j] == 0)
					continue;

				int currNum = blocks[i][j];

				if (blocks[i + 1][j] == currNum && blocks[i][j + 1] == currNum && blocks[i + 1][j + 1] == currNum)
				{
					q.push(make_pair(i, j));
					q.push(make_pair(i + 1, j));
					q.push(make_pair(i, j + 1));
					q.push(make_pair(i + 1, j + 1));
				}
			}
		}

		if (q.empty())
			break;

		while (!q.empty())														// 추출된 부분 삭제
		{
			blocks[q.front().first][q.front().second] = 0;
			q.pop();
		}

		for (int i = m - 1; i > 0; i--)											// 빈 공간으로 내려주기
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (blocks[i][j] != 0)
					continue;

				for (int r = i - 1; r >= 0; r--)
				{
					if (blocks[r][j] == 0)
						continue;

					blocks[i][j] = blocks[r][j];
					blocks[r][j] = 0;
					break;
				}
			}
		}
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (blocks[i][j] == 0)
				answer++;
		}
	}

	return answer;
}