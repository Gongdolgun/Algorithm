#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int n, m;
int dp[10001];
vector<int> coin;

// 코인 저장
// 1~m까지 coin[i]가 m보다 작을때 계산
// dp[i] = (m - coin[i]) + 1

void input(){
	cin >> n >> m;

	coin.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}

	for(int j = 1; j <= m; j++)
	{
		dp[j] = 10001;
	}
}

void solution() {
	for (int i = 1; i <= n; i++)
	{
		for(int j = coin[i]; j <= m; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if(dp[m] == 10001)
	{
		cout << -1;
		return;
	}

	cout << dp[m];
}

void solve(){
	input();
	solution();
}

int main() {

	solve();

	return 0;
}