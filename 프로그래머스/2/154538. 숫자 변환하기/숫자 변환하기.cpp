#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <bitset>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <set>

using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

vector<int> v(1000001, INF);

int solution(int x, int y, int n) {
    int answer = 0;

	v[y] = 0;

	for(int i = y; i > x; i--)
	{
		if(v[i] != INF)
		{
			if (i % 3 == 0)
				v[i / 3] = min(v[i] + 1, v[i / 3]);

			if (i % 2 == 0)
				v[i / 2] = min(v[i] + 1, v[i / 2]);

			if (i - n > 0)
				v[i - n] = min(v[i] + 1, v[i - n]);
		}
	}

	v[x] == INF ? answer = -1 : answer = v[x];

    return answer;
}