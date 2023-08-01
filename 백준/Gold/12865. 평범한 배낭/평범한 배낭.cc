#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n, k;
int w, v;
vector<pair<int, int>> vec(101);
int DP[101][100001];

void input(){
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
	{
		cin >> w >> v;
		vec[i] = make_pair(w, v);
	}
}

void solution() {
	for (int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(vec[i].first > j)
			{
				DP[i][j] = DP[i-1][j];
				continue;
			}

			DP[i][j] = max(vec[i].second + DP[i - 1][j - vec[i].first], DP[i - 1][j]);
		}
	}

	cout << DP[n][k];
}

void solve(){
	input();
	solution();
}

int main() {

	solve();

	return 0;
}