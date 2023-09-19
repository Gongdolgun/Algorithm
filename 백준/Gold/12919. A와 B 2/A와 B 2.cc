#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;
string A;
string B;
string tmp;

void input()
{
    cin >> A >> B;
}

void solution(string s, string t)
{
    if (s == t)
    {
        cout << 1;
        exit(0);
    }

    if (s.length() >= t.length())
        return;

    if(t[t.length()-1] == 'A')
    {
        tmp = t;
        tmp.erase(tmp.length()-1);
        solution(s, tmp);
    }

    if(t[0] == 'B')
    {
        tmp = t;
        tmp.erase(tmp.begin());
        reverse(tmp.begin(), tmp.end());
        solution(s, tmp);
    }
}

int main()
{
    input();
    solution(A, B);
    cout << 0;
    return 0;
}