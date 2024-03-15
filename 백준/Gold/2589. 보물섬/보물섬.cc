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
#define INF 9999999999
#define ll long long

using namespace std;
int n, m;
vector<vector<int>> coo;
queue<pair<int, int>> q;
vector<vector<int>> check;

int x_pos[4] = { 1, 0, -1, 0 };
int y_pos[4] = { 0, 1, 0, -1 };

int bfs()
{
    int result = -1;

    while(!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int next_x = curr_x + x_pos[i];
            int next_y = curr_y + y_pos[i];

            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
                continue;

            if(coo[next_x][next_y] == 1)
                continue;

            if(check[next_x][next_y] > 0)
                continue;

            check[next_x][next_y] = check[curr_x][curr_y] + 1;
            result = max(result, check[next_x][next_y]);
            q.push(make_pair(next_x, next_y));
        }
    }

    return result;
}

void solution()
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(coo[i][j] == 0)
            {
                //새로운 BFS 탐색을 위해 check 배열 초기화
                for (int k = 0; k < n; k++)
                    fill(check[k].begin(), check[k].end(), 0);
                
                // 시작점에 대한 check 값을 1로 초기화
                check[i][j] = 1;
                q.push(make_pair(i, j));
                answer = max(answer, bfs()-1); // 시작점도 포함하므로 가장 긴 거리에서 -1을 해줍니다.
            }
        }
    }

    cout << answer;
}

int main()
{
    FASTIO

    cin >> n >> m;
    coo.resize(n, vector<int>(m));
    check.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m ; j++)
            s[j] == 'W' ? coo[i][j] = 1 : coo[i][j] = 0;
    }

    solution();

    return 0;
}
