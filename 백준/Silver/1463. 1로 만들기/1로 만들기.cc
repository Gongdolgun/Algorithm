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
#include <unordered_map>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

int solution(int num)
{
	vector<int> dp(num + 1);
	dp[1] = 0;

	for(int i = 2; i <= num; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);

		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	return dp[num];
}

int main()
{
	int num = 0;
	cin >> num;

    cout << solution(num);
}