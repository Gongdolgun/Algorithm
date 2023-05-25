#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    float temp = 0;
    float stage = 0;
    bool exist = false;
    vector<float> fail;
    vector<float> fail2;


    for(int i = 1; i <= N; i ++)
    {
        float num = 0;

	    for(int j = 0; j < stages.size(); j++)
	    {
            if (stages[j] >= i)         // 해당 스테이지에 머무르고 있거나, 클리어한 사람
            {
                ++temp;


				if (stages[j] == i)        // 해당 스테이지에 머물러 있는 사람
					++stage;
            }
	    }

        if(temp == 0)
        {
            fail.push_back(0);
            fail2.push_back(0);

            continue;
        }

        num = stage / temp;
        fail.push_back(num);       // 각 스테이지별 실패율
        fail2.push_back(num);

        temp = 0;
        stage = 0;
    }

    sort(fail2.begin(), fail2.end(), greater<>());

    for(int k = 0; k < N; k++)
    {
	    for(int r = 0; r < N; r++)
	    {
            if (fail2[k] == fail[r])
            {
                if (!answer.empty())            // answer이 비어있지 않으면 검사
                {
                    for (int q = 0; q < answer.size(); q++)
                    {
                        if (answer[q] == r + 1)
                        {
                            exist = true;
                            break;
                        }
                    }

                    if (!exist)
                        answer.push_back(r + 1);

                    exist = false;
                }

                else                            // 비어있으면 push_back
                    answer.push_back(r + 1);
            }
	    }
    }

    return answer;
}

int main()
{
    vector<int> stages = { 1, 1, 1, 1, 1 };

    stages = solution(4, stages);

    for(auto Stage : stages)
    {
        cout << Stage << ' ';
    }

    return 0;
}