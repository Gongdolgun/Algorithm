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

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

int n, m;
vector<int> nums;
vector<int> tmp(10);
vector<bool> visited(10);

void dfs(int cnt)
{
	if(cnt == m)
	{
		for(int i = 0; i < m; i++)
			cout << tmp[i] << ' ';

		cout << '\n';
		return;
	}

	for(int i = 0; i < nums.size(); i++)
	{
		if(!visited[i])
		{
			tmp[cnt] = nums[i];
			dfs(cnt + 1);
		}
	}
}

int main()
{
	FASTIO

	cin >> n >> m;
	nums.resize(n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	dfs(0);
}