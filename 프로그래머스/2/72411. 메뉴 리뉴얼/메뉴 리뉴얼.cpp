#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int x = 0; x < orders.size(); x++)
    {
        sort(orders[x].begin(), orders[x].end());

        for (int i = 0; i < course.size(); i++)
        {
            if(orders[x].size() < course[i])
                continue;

            vector<int> idx;

            for (int j = 0; j < course[i]; j++)
                idx.push_back(1);

            for (int r = 0; r < orders[x].size() - course[i]; r++)
                idx.push_back(0);

            sort(idx.begin(), idx.end());

            do
            {
                string strtmp;

                for (int i = 0; i < idx.size(); i++)
                {
                    if (idx[i] == 1)
                        strtmp += orders[x][i];
                }

                m[strtmp]++;
            } while (next_permutation(idx.begin(), idx.end()));
        }
    }

    for(int i = 0; i < course.size(); i++)
    {
        int maxnum = 0;

        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            if (iter->first.size() == course[i])
                maxnum = max(maxnum, iter->second);
        }

        for(auto iter = m.begin(); iter != m.end(); iter++)
        {
            if (maxnum < 2)
                break;

            if(iter->first.size() == course[i] && iter->second == maxnum)
            {
                bool isDuplicate = false;
                for(int j = 0; j < answer.size(); j++)
                {
                    if(answer[j] == iter->first)
                    {
                        isDuplicate = true;
                        break;
                    }
                }
                if(!isDuplicate)
                    answer.push_back(iter->first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> orders(n);
    vector<int> course(m);

    for(int i = 0; i < n; i++)
    {
        cin >> orders[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> course[i];
    }

    vector<string> result = solution(orders, course);

    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}
