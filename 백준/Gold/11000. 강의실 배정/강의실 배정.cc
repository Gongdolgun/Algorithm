#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

void solution(vector<pair<int, int>> time)
{
	sort(time.begin(), time.end());
	priority_queue<int, vector<int>, greater<>> pq;

	for(int i = 0; i < time.size(); i++)
	{
		pq.push(time[i].second);
		if (time[i].first >= pq.top())
			pq.pop();
	}

	cout << pq.size();
}

int main()
{
	int a;
	cin >> a;

	vector<pair<int, int>> time;

	for (int i = 0; i < a; i++)
	{
		int x, y;
		cin >> x >> y;
		time.push_back(make_pair(x, y));
	}

	solution(time);

	return 0;
}