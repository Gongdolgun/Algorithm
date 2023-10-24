#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;
int num = 1;
map<string, int> m;

vector<int> solution(string msg) {
	vector<int> answer;

	string str;
	string prev_str;

	for (int i = 0; i < 26; i++)
	{
		str += 'A' + i;
		m[str] = i + 1;
		num++;
		str.clear();
	}

	str += msg[0];
	prev_str = str;

	if(msg.length() == 1)
	{
		answer.push_back(m[str]);
		return answer;
	}

	for(int i = 1; i < msg.length(); i++)
	{
		str += msg[i];

		if(m[str] != 0)
		{
			prev_str = str;
			if (i == msg.length() - 1)
				answer.push_back(m[str]);
			continue;
		}

		answer.push_back(m[prev_str]);
		m[str] = num;
		num++;
		str.clear();
		prev_str.clear();
		str += msg[i];
		prev_str += msg[i];

		if (i == msg.length() - 1)
			answer.push_back(m[str]);
	}

	return answer;
}