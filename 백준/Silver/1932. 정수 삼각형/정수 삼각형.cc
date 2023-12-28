#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> v[i][j];

	dp[0][0] = v[0][0];

	int answer = dp[0][0];

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(j == 0)
			{
				dp[i][j] = v[i][j] + dp[i - 1][0];
			}

			else if(j == i)
			{
				dp[i][j] = v[i][j] + dp[i - 1][i - 1];
			}

			else
			{
				dp[i][j] = v[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}

			answer = max(answer, dp[i][j]);
		}
	}

	cout << answer;

	return 0;
}