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
	priority_queue<int, vector<int>, greater<>> pq;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		pq.push(tmp);
	}

	int sum = 0;

	while(!pq.empty())
	{
		if (pq.size() == 1)
		{
			cout << sum;
			break;
		}

		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();

		sum += a + b;
		pq.push(a + b);
	}

	return 0;
}