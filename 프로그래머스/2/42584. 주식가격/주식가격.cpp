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

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for(int i = 0; i < prices.size(); i++)
	{
		int tmp = 0;
		for(int j = i + 1; j < prices.size(); j++)
		{
			tmp++;

			if (prices[i] > prices[j])
				break;
		}

		answer.push_back(tmp);
	}

	return answer;
}

int main()
{
	FASTIO

	
}