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

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

int n, m;
int cx, cy, head;
int arr[51][51];
bool check[51][51];
int pos_x[4] = { 1, 0, -1, 0 };
int pos_y[4] = { 0, 1, 0, -1 };

//1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
//2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
//1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
//2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
//3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
//1. 반시계 방향으로 90도 회전한다.
//2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
//3. 1번으로 돌아간다.

void solution()
{
    int cnt = 1;
    check[cx][cy] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(cx, cy));

    while(!q.empty())
    {
        int cur_x = q.front().first;
    	int cur_y = q.front().second;
        q.pop();
        check[cur_x][cur_y] = true;

        bool dirty = false;
        for(int i = 0; i < 4; i++)
        {
            int next_x = cur_x + pos_x[i];
            int next_y = cur_y + pos_y[i];

            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
                continue;

            if(check[next_x][next_y] == true)
                continue;

            if(arr[next_x][next_y] == 1)
                continue;

            dirty = true;
        }

        if(!dirty)
        {
	        switch (head)
	        {
				case 0:                     // 헤드가 북쪽
                if(arr[cur_x + 1][cur_y] == 1)
                {
                    cout << cnt;
                    return;
                }
                q.push(make_pair(cur_x + 1, cur_y));
                break;

				case 1:                     // 헤드가 동쪽
                if (arr[cur_x][cur_y - 1] == 1)
                {
                    cout << cnt;
                    return;
                }
                q.push(make_pair(cur_x, cur_y - 1));
                break;

                case 2:                     // 헤드가 남쪽
                if (arr[cur_x - 1][cur_y] == 1)
                {
                    cout << cnt;
                    return;
                }

                q.push(make_pair(cur_x - 1, cur_y));
                break;

                case 3:                     // 헤드가 서쪽
                if (arr[cur_x][cur_y + 1] == 1)
                {
                    cout << cnt;
                    return;
                }

                q.push(make_pair(cur_x, cur_y + 1));
                break;
	        }
        }

        else
        {
            for (int i = 0; i < 4; i++)
            {
                head = head - 1;
                if (head == -1)
                    head = 3;

                switch (head)
                {
                case 0:                     // 헤드가 북쪽
                    if (check[cur_x - 1][cur_y] == false && arr[cur_x - 1][cur_y] == 0)
                    {
                        q.push(make_pair(cur_x - 1, cur_y));
                        cnt++;
                    }
                    break;

                case 1:                     // 헤드가 동쪽
                    if (check[cur_x][cur_y + 1] == false && arr[cur_x][cur_y + 1] == 0)
                    {
                        q.push(make_pair(cur_x, cur_y + 1));
                        cnt++;
                    }
                    break;

                case 2:                     // 헤드가 남쪽
                    if (check[cur_x + 1][cur_y] == false && arr[cur_x + 1][cur_y] == 0)
                    {
                        q.push(make_pair(cur_x + 1, cur_y));
                        cnt++;
                    }
                    break;

                case 3:                     // 헤드가 서쪽
                    if (check[cur_x][cur_y - 1] == false && arr[cur_x][cur_y - 1] == 0)
                    {
                        q.push(make_pair(cur_x, cur_y - 1));
                        cnt++;
                    }
                    break;
                }

                if (!q.empty())
                    break;
            }
        }
    }

    cout << cnt;
}

int main()
{
    FASTIO

	cin >> n >> m >> cx >> cy >> head;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    solution();

    return 0;
}