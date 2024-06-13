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

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	map<char, int> m;
	queue<char> q;

	for(int i = 0; i < skill_trees.size(); i++)
	{
		bool canSkill = true;

		for (auto& s : skill)
		{
			q.push(s);
			m[s] = 1;
		}

		for(int j = 0; j < skill_trees[i].size(); j++)
		{
			if (m[skill_trees[i][j]] == 1 && q.front() == skill_trees[i][j])
			{
				q.pop();
				continue;
			}

			if (m[skill_trees[i][j]] == 1 && q.front() != skill_trees[i][j])
			{
				canSkill = false;
				break;
			}
		}

		if (canSkill)
			answer++;

		m.clear();
		queue<char> qtmp;
		q = qtmp;
	}

	return answer;
}