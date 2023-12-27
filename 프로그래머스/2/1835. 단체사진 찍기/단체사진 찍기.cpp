#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

bool Rules(char oper, int diff, int num)
{
    if (oper == '<')
        return num > diff;

    else if (oper == '=')
        return num == diff;

    else
        return num < diff;
}

int solution(int n, vector<string> data) {
    int answer = 0;

    string friends = "ACFJMNRT";
    sort(friends.begin(), friends.end());

    do
    {
        bool check = true;
	    for(string str : data)
	    {
            int first = friends.find(str[0]);
            int second = friends.find(str[2]);
            int num = str[4] - '0';
            int diff = abs(second - first) - 1;

            check = Rules(str[3], diff, num);

            if(check)
                continue;

            break;
	    }

        if (check)
            answer++;
    }
    while (next_permutation(friends.begin(), friends.end()));

    cout << answer;
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> vstr(n);
    for (int i = 0; i < n; i++)
        cin >> vstr[i];

    solution(n, vstr);

    return 0;
}