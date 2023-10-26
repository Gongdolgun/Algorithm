#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

bool check(string user_id, string banned_id)
{
	for(int i = 0; i < user_id.length(); i++)
	{
		if (user_id.length() != banned_id.length())
			return false;

		if (user_id[i] == banned_id[i] || banned_id[i] == '*')
			continue;

		return false;
	}

	return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

	sort(user_id.begin(), user_id.end());
	set<string> s;
    do
    {
		vector<string> vtmp;
		string str_tmp = "";
	    for(int i = 0; i < banned_id.size(); i++)
	    {
			if (check(user_id[i], banned_id[i]))
				vtmp.push_back(user_id[i]);
	    }

		if(vtmp.size() == banned_id.size())
		{
			sort(vtmp.begin(), vtmp.end());
			for (auto& V : vtmp)
				str_tmp += V;

			s.insert(str_tmp);
		}
    }
    while (next_permutation(user_id.begin(), user_id.end()));

	answer = s.size();

	cout << answer;

    return answer;
}