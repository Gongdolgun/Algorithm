#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int cnt;

void check(string str)
{
    stack<char> s_start;
    queue<char> s_end;
    bool exist = false;

    for(int i = 0; i < str.length(); i++)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
            s_start.push(str[i]);

        else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
        {
            if (str[i] == ']')
            {
                for (int r = 0; r < i; r++)
                    if (str[r] == '[')
                    {
                        exist = true;
                        break;
                    }
            }

            else if (str[i] == '}')
            {
                for (int n = 0; n < i; n++)
                    if (str[n] == '{')
                    {
                        exist = true;
                        break;
                    }
            }

            else if (str[i] == ')')
            {
                for (int m = 0; m < i; m++)
                    if (str[m] == '(')
                    {
                        exist = true;
                        break;
                    }
            }

            if (exist == false)
                return;

            s_end.push(str[i]);
        }

        if(!s_start.empty() && !s_end.empty())
        {
            if(s_start.top() == '[' && s_end.front() == ']')
            {
                s_start.pop();
                s_end.pop();
                continue;
            }

            if (s_start.top() == '{' && s_end.front() == '}')
            {
                s_start.pop();
                s_end.pop();
                continue;
            }

            if (s_start.top() == '(' && s_end.front() == ')')
            {
                s_start.pop();
                s_end.pop();
                continue;
            }
        }
    }

    /*int tmp = s_start.size();

    for(int r = 0; r < tmp; r++)
    {
        if (s_start.empty())
            break;

        if (s_start.top() == '[')
            if (!s_end.empty() && s_end.front() == ']')
            {
                s_start.pop();
                s_end.pop();
                continue;
            }

        if (s_start.top() == '{')
            if (!s_end.empty() && s_end.front() == '}')
            {
                s_start.pop();
                s_end.pop();
                continue;
            }

        if (s_start.top() == '(')
            if (!s_end.empty() && s_end.front() == ')')
            {
                s_start.pop();
                s_end.pop();
                continue;
            }
    }*/

    if (!s_start.empty())
        return;

    if (!s_end.empty())
        return;

    cnt++;
}

int solution(string s) {
    int answer = 0;

    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[0];
        s.erase(0, 1);
        s = s + ch;


        if (s[0] == ']' || s[0] == '}' || s[0] == ')')
            continue;

        check(s);
    }

    if (cnt != 0)
        answer = cnt;

    cout << answer;

    return answer;
}

int main()
{
    string str;
    cin >> str;

    solution(str);
    return 0;
}