#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <tuple>

using namespace std;

map<string, string> m;
vector<pair<string, string>> v;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for(int i = 0; i < record.size(); i++)
    {
		int tmp = 0;
		string Init;
		string userID;
		string userNickName = "";

	    for(int j = 0; j < record[i].size(); j++)
	    {
			if (record[i][j] == ' ')
				break;

			Init += record[i][j];
			tmp = j;
	    }

		for (int j = tmp + 2; j < record[i].size(); j++)
		{
			if (record[i][j] == ' ')
				break;

			userID += record[i][j];
			tmp = j;
		}

		v.push_back(make_pair(Init, userID));

		if(Init == "Enter" || Init == "Change")
		{
			for (int j = tmp + 2; j < record[i].size(); j++)
			{
				if (j >= record[i].size())
					break;

				userNickName += record[i][j];
				m[userID] = userNickName;
			}
		}
    }

	for (int i = 0; i < v.size(); i++)
	{
		string str;

		if (v[i].first == "Enter")
			str = m[v[i].second] + "님이 들어왔습니다.";

		else if (v[i].first == "Leave")
			str = m[v[i].second] + "님이 나갔습니다.";

		else
			continue;

		answer.push_back(str);
	}

    return answer;
}

int main()
{
	int n;
	vector<string> v;

	cin >> n;
	cin.ignore();

	for(int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);

		v.push_back(str);
	}

	solution(v);

	return 0;
}