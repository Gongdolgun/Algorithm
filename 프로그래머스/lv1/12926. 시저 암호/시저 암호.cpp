#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            answer.push_back(' ');
            continue;
        }

        for(int j = 1; j <= n; j++)
        {
            s[i] = s[i] + 1;

            if (s[i] > 'z')
                s[i] = 'a';

            else if (s[i] > 'Z' && s[i] < 'a')
                s[i] = 'A';
        }

        answer.push_back(s[i]);
    }

    return answer;
}