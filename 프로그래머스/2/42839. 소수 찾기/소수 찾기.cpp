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

bool is_prime(int n)
{
	if (n < 2)
		return false;

	for(int i = 2; i * i <= n; i++)
	{
        if (n % i == 0)
            return false;
	}

    return true;
}

int solution(string numbers) {
	int answer = 0;

	vector<char> v;
	for (auto& number : numbers)
		v.push_back(number);

	sort(v.begin(), v.end());
	map<int, int> m;

	for(int i = 0; i < v.size(); i++)
	{
		do
		{
			string strtmp;
			for(int j = 0; j <= i; j++)
				strtmp += v[j];

			if (is_prime(stoi(strtmp)) && m[stoi(strtmp)] == 0)
			{
				m[stoi(strtmp)] = 1;
				answer++;
			}

		} while (next_permutation(v.begin(), v.end()));
	}

	return answer;
}