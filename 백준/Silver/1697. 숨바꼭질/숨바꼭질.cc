#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define INF 100001

using namespace std;

vector<int> vec(INF);
vector<bool> check(INF);

int main()
{
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));

    

    while(!q.empty())
    {
        int tmp = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(tmp == k)
        {
            cout << cnt;
            break;
        }

        if(tmp + 1 >= 0 && tmp + 1 < INF && !check[tmp + 1])
        {
            vec[tmp + 1] = cnt;
            check[tmp + 1] = true;
            q.push(make_pair(tmp + 1, cnt + 1));
        }

        if(tmp - 1 >= 0 && tmp - 1 < INF && !check[tmp - 1])
        {
            vec[tmp - 1] = cnt;
            check[tmp - 1] = true;
            q.push(make_pair(tmp - 1, cnt + 1));
        }

        if(tmp * 2 >= 0 && tmp * 2 < INF && !check[tmp * 2])
        {
            vec[tmp * 2] = cnt;
            check[tmp * 2] = true;
            q.push(make_pair(tmp * 2, cnt + 1));
        }
    }

    return 0;
}