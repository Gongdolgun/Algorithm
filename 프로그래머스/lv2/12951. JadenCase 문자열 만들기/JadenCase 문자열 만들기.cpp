#include <string>
#include <vector>
#include <iostream>

using namespace std;

int num = 'a' - 'A';

string solution(string s) {
    string answer = "";
    string str;
    vector<string> vec;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            if (!str.empty())
            {
                vec.push_back(str);
                str.clear();
            }

            vec.push_back(" ");
            continue;
        }

        str += s[i];

        if (i == s.length() - 1)
            vec.push_back(str);

    }

    for (auto& Vec : vec)
    {
        if(Vec != " ")
        {
            for(int i = 0; i < Vec.size(); i++)
            {
	            if(Vec[i] < 'A')
	            {
                    answer += Vec[i];
                    continue;
	            }
                    

                if (i == 0 && Vec[i] >= 'a' && Vec[i] <= 'z')
                {
                    Vec[i] -= num;
                    answer += Vec[i];
                    continue;
                }

            	if (i > 0 && Vec[i] >= 'A' && Vec[i] <= 'Z')
                    Vec[i] += num;

                answer += Vec[i];
            }
        }

        else 
			answer += ' ';
    }

    cout << answer;

    return answer;
}

int main()
{
    string test_str;

    getline(cin, test_str);

    solution(test_str);

    return 0;
}