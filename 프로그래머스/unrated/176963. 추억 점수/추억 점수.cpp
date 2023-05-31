#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int sum = 0;

    map<string, int> data;

    for(int i = 0; i < name.size(); i++)
    {
        data.insert({ name[i], yearning[i] });
    }

    for(int j = 0; j < photo.size(); j++)
    {
	    for(int r = 0; r < photo[j].size(); r++)
	    {
            string key = photo[j][r];                   // 찾을 키값 정의
            auto dFind = data.find(key);                // 키를 못찾으면 data.end()반환

            if (dFind != data.end())                    // 키를 찾았을 때 dFind->second(Value값)을 sum에 더함
                sum += dFind->second;

            else
                sum += 0;
	    }
        answer.push_back(sum);
        sum = 0;
    }

    return answer;
}