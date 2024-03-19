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
vector<char> behavior(10001);

int solution()
{
    queue<pair<int, int>> q;
    int t = 0;
    int head = 1;       // 0 - 북쪽, 1 - 동쪽, 2 - 남쪽, 3 - 서쪽
    int cx = 1, cy = 1;

    coo[1][1] = 1;
    q.push({ 1, 1 });

    while (1)
    {
        if(behavior[t] == 'D')
        {
            head++;
            if (head > 3)
                head = 0;
        }

        else if (behavior[t] == 'L')
        {
            head--;
            if (head < 0)
                head = 3;
        }

	    switch (head)
	    {
	    case 0:
            if (cx - 1 < 1 || cx - 1 > n || cy < 1 || cy > n)                 // 다음 칸이 벽이면 return
                return t;

            if (coo[cx - 1][cy] == 1)                                           // 다음 칸이 뱀의 몸통이면 return
                return t;

            if (coo[cx - 1][cy] == 2)                                           // 다음 칸이 사과라면 길이만 길어지기                                          
            {
                coo[cx - 1][cy] = 1;
                q.push({ cx - 1, cy });
            }

            else                                                                // 다음 칸이 사과가 아니면 꼬리 줄이고 queue에 추가 
            {
                coo[cx - 1][cy] = 1;
                coo[q.front().first][q.front().second] = 0;
                q.pop();
                q.push({ cx - 1, cy });
            }
            t++;
            cx--;
            break;

	    case 1:
            if (cx < 1 || cx > n || cy + 1 < 1 || cy + 1 > n)                 // 다음 칸이 벽이면 return
                return t;

            if (coo[cx][cy + 1] == 1)                                           // 다음 칸이 뱀의 몸통이면 return
                return t;

            if (coo[cx][cy + 1] == 2)                                           // 다음 칸이 사과라면 길이만 길어지기                                          
            {
                coo[cx][cy + 1] = 1;
                q.push({ cx, cy + 1 });
            }

            else                                                                // 다음 칸이 사과가 아니면 꼬리 줄이고 queue에 추가 
            {
                coo[cx][cy + 1] = 1;
                coo[q.front().first][q.front().second] = 0;
                q.pop();
                q.push({ cx, cy + 1 });
            }
            t++;
            cy++;
	    	break;

        case 2:
            if (cx + 1 < 1 || cx + 1 > n || cy < 1 || cy > n)                 // 다음 칸이 벽이면 return
                return t;

            if (coo[cx + 1][cy] == 1)                                           // 다음 칸이 뱀의 몸통이면 return
                return t;

            if (coo[cx + 1][cy] == 2)                                           // 다음 칸이 사과라면 길이만 길어지기                                          
            {
                coo[cx + 1][cy] = 1;
                q.push({ cx + 1, cy });
            }

            else                                                                // 다음 칸이 사과가 아니면 꼬리 줄이고 queue에 추가 
            {
                coo[cx + 1][cy] = 1;
                coo[q.front().first][q.front().second] = 0;
                q.pop();
                q.push({ cx + 1, cy });
            }
            t++;
            cx++;
            break;

        case 3:
            if (cx < 1 || cx > n || cy - 1 < 1 || cy - 1 > n)                 // 다음 칸이 벽이면 return
                return t;

            if (coo[cx][cy - 1] == 1)                                           // 다음 칸이 뱀의 몸통이면 return
                return t;

            if (coo[cx][cy - 1] == 2)                                           // 다음 칸이 사과라면 길이만 길어지기                                          
            {
                coo[cx][cy - 1] = 1;
                q.push({ cx, cy - 1 });
            }

            else                                                                // 다음 칸이 사과가 아니면 꼬리 줄이고 queue에 추가 
            {
                coo[cx][cy - 1] = 1;
                coo[q.front().first][q.front().second] = 0;
                q.pop();
                q.push({ cx, cy - 1 });
            }
            t++;
            cy--;
            break;
	    }

        /*for(int i = 0; i < n; i++)
        {
	        for(int j = 0; j < n; j++)
	        {
                cout << coo[i][j] << ' ';
	        }

            cout << '\n';
        }

        cout << '\n';*/
    }
}

int main()
{
    FASTIO

	cin >> n >> m;

    coo.resize(n + 1, vector<int>(n + 1));

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        coo[x][y] = 2;
    }

    int cnt;
    cin >> cnt;

    for(int i = 0; i < cnt; i++)
    {
        int t;
        char dir;

        cin >> t >> dir;
        behavior[t] = dir;
    }

    cout << solution() + 1;

    return 0;
}
