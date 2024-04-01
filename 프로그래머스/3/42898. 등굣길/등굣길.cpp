#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <bitset>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

vector<vector<int>> DP;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    DP.resize(101, vector<int>(101));

    for(auto& P : puddles)
    {
        DP[P[1]][P[0]] = -1;
    }

    DP[1][1] = 1;

    for(int i = 1; i <= n; i++)
    {
	    for(int j = 1; j <= m; j++)
	    {
            if(i == 1 && j == 1)
            {
                DP[i][j] = 1;
                continue;
            }

            if (DP[i][j] == -1)
            {
                DP[i][j] = 0;
                continue;
            }

            if (i == 1)
                DP[i][j] = DP[i][j - 1];

            if (j == 1)
                DP[i][j] = DP[i - 1][j];

		    if(DP[i][j] != -1)
                DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000007;
	    }
    }

    cout << DP[n][m];

    return DP[n][m];
}