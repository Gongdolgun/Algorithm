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

// points의 좌표는 1번 포인트 부터 n번 포인트까지 주어짐
// 최단 경로 탐색이지만 행 이동이 열 이동보다 우선순위가 높음
// 중간에 각 포인트들이 마주치는 횟수를 리턴

vector<map<pair<int, int>, int>> paths;

int Calculate(const vector<vector<int>>& points, vector<int> route)
{
	int answer = 0;
	int sx = points[route[0] - 1][0], sy = points[route[0] - 1][1];
	int time = 0;

	for (int i = 1; i < route.size(); i++)
	{
		int ex = points[route[i] - 1][0], ey = points[route[i] - 1][1];

		while (1)
		{
			if (sx == ex && sy == ey)
			{
				break;
			}

			paths[time][make_pair(sx, sy)]++;

			if (paths[time][make_pair(sx, sy)] == 2)
				answer++;

			// 같은 행에 있다면
			if (sx == ex)
			{
				if (sy > ey)
					sy--;

				else
					sy++;
			}

			// 같은 행에 있지 않다면
			else
			{
				if (sx > ex)
					sx--;

				else
					sx++;
			}

			time++;
		}
	}

	paths[time][make_pair(sx, sy)]++;
	if (paths[time][make_pair(sx, sy)] == 2)
		answer++;

	return answer;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
	int answer = 0;

	paths.resize(20001);

	for(int i = 0; i < routes.size(); i++)
		answer += Calculate(points, routes[i]);

	return answer;
}

int main()
{
	FASTIO

	cout << solution({ {3, 2}, {6, 4}, {4, 7}, {1, 4} }, { {4, 2}, {1, 3}, {4, 2}, {4, 3} });
}