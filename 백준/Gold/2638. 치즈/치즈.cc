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
#include <cstring>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

int arr[101][101];
int sided[101][101];
bool check[101][101];
int m, n, times, result;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool solution()
{
    int cnt = 0;
    times++;
    check[0][0] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while(!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];

            if(next_x < 0 || next_x > n || next_y < 0 || next_y > m)
                continue;

            if(check[next_x][next_y] == true)
                continue;

            if (arr[next_x][next_y] == 0)
            {
                q.push(make_pair(next_x, next_y));
                check[next_x][next_y] = true;
            }

            else
            {
                if (sided[next_x][next_y] > 0)
                {
                    arr[next_x][next_y] = 0;
                    check[next_x][next_y] = true;
                    cnt++;
                }

                else
                    sided[next_x][next_y]++;
            }
        }
    }

    if (cnt == 0) // 치즈가 하나도 없을 때
    {
        cout << --times;
        return false;
    }

    else
    {
        result = cnt;
        return true;
    }
}

int main()
{
    FASTIO

	cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;

            arr[i][j] = tmp;
        }
    }

    while(1)
    {
        if (!solution())
            break;

        memset(check, false, sizeof(check));
        memset(sided, 0, sizeof(sided));
    }

    return 0;
}