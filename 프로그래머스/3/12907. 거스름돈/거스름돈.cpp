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

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

int DP[100001];

int solution(int n, vector<int> money) {
    int answer = 0;

    DP[0] = 1;

    for(int i = 0; i < money.size(); i++)
    {
	    for(int j = money[i]; j <= n; j++)
	    {
            DP[j] = DP[j - money[i]] + DP[j];
	    }
    }

    answer = DP[n];
    cout << answer;

    return answer;
}