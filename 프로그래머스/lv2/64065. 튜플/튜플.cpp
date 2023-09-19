#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int, int>> vtmp;
    bool check = false;
    string str_tmp;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            str_tmp += s[i];
            continue;
        }

        else
        {
            if(!str_tmp.empty())
            {
                for(int j = 0; j < vtmp.size(); j++)
                {
                    if (vtmp[j].second == stoi(str_tmp))
                    {
                        vtmp[j].first++;
                        check = true;
                        break;
                    }
                }

                if(check == false)
                {
                    vtmp.push_back(make_pair(1, stoi(str_tmp)));
                }
                check = false;
                str_tmp.clear();
            }
        }
    }

    sort(vtmp.begin(), vtmp.end(), greater<>());
    for(auto& Vec : vtmp)
    {
        answer.push_back(Vec.second);
    }

    return answer;
}