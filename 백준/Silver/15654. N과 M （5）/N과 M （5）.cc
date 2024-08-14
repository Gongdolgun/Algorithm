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

int main()
{
	FASTIO

	int n, m;
	cin >> n >> m;

	vector<int> nums(n);
	vector<int> v(n);
	vector<vector<int>> res;

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	for (int i = 0; i < m; i++)
		v[i] = 1;

	do
	{
		vector<int> tmp;
		for (int i = 0; i < n; i++)
			if (v[i])
				tmp.push_back(nums[i]);

		sort(tmp.begin(), tmp.end());
		do
		{
			res.push_back(tmp);
		}
		while (next_permutation(tmp.begin(), tmp.end()));
	}
	while (prev_permutation(v.begin(), v.end()));

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}