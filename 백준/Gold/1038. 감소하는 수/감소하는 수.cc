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

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

int N;
long long d[1000001];

void solution() {
	if (N <= 10) {
		cout << N;
		return;
	}

	for (int i = 0; i < 10; i++) {
		d[i] = i;
	}

	int num = 10;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < d[i] % 10; j++) {
			d[num] = d[i] * 10 + j;
			num++;
		}
	}

	if (d[N] == 0) cout << -1;
	else cout << d[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	solution();

	return 0;
}