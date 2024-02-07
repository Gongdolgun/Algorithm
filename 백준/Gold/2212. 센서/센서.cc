#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

ll n, k, answer = 0;
ll sensor[10001];
ll radar[10001];

int main()
{
    FASTIO

	cin >> n;
	cin >> k;
	for (ll i = 1; i <= n; i++) 
		cin >> sensor[i];

	sort(sensor + 1, sensor + n + 1);

	for (ll i = 1; i < n; i++) 
		radar[i] = sensor[i + 1] - sensor[i];

	sort(radar + 1, radar + n, greater<>());

	for (ll i = k; i < n; i++) 
		answer += radar[i];

	cout << answer << endl;

    return 0;
}