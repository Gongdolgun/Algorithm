#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int n, m;
int dp[21][201];
int arr[21][2];

void input(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
}

void solution() {
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j - arr[i][0] >= 0)
				dp[i][j] = max(dp[i - 1][j - arr[i][0]] + arr[i][1], dp[i - 1][j]);
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
		}
	}

	cout << dp[m][n];
}

void solve(){
	input();
	solution();
}

int main() {

	solve();

	return 0;
}