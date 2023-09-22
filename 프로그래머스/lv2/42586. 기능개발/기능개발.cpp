#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> date;

    for(int i = 0; i < progresses.size(); i++)
    {
        int tmp = 100 - progresses[i];

        if (tmp % speeds[i] != 0)
            date.push_back(tmp / speeds[i] + 1);

        else
            date.push_back(tmp / speeds[i]);
    }

    int cnt = date[0];
    int c = 1;
    for(int i = 1; i < date.size(); i++)
    {
        int tmp = cnt;
        cnt = max(cnt, date[i]);

        if(cnt == tmp)
        {
            c++;
            if (i == date.size() - 1)
            {
                answer.push_back(c);
                break;
            }
        }

        else
        {
            answer.push_back(c);
            c = 1;

            if (i == date.size() - 1)
            {
                answer.push_back(c);
                break;
            }
        }
    }

    return answer;
}