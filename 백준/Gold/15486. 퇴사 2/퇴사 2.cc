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

int n;
vector<pair<int, int>> v(1500001);
vector<int> DP(1500001);

void solution()
{
    for(int i = 1; i <= n + 1; i++)
    {
        DP[i] = max(DP[i], DP[i - 1]);

        DP[i + v[i].first] = max(DP[i + v[i].first], DP[i] + v[i].second);
    }

    cout << DP[n + 1];
}

int main()
{
    FASTIO

	cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int time, price;
        cin >> time >> price;

        v[i] = make_pair(time, price);
    }

    solution();

    return 0;
}