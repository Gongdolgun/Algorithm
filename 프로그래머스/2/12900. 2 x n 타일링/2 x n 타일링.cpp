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

int arr[60001];

int solution(int n) {
    int answer = 0;

	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000007;

	answer = arr[n];

	return answer;
}

int main()
{
	FASTIO

		solution(4);
}