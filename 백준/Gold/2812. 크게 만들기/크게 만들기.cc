#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

int n, k;
string number;

void solution()
{
    int cnt = 0;
    stack<char> s;
    s.push(number[0]);

    for(int i = 1; i < number.length(); i++)
    {
        if(cnt == k)
        {
            s.push(number[i]);
            continue;
        }

	    while (1)
	    {
            if(cnt == k)
            {
                s.push(number[i]);
                break;
            }

		    if(s.top() >= number[i])
		    {
			    s.push(number[i]);
                break;
		    }

		    else
		    {
                s.pop();
                cnt++;

                if (s.empty())
                {
                    s.push(number[i]);
                    break;
                }
		    }
	    }
    }

    if(cnt != k)
    {
        while (cnt != k)
        {
            s.pop();
            cnt++;
        }
    }

    string answer;
    answer.resize(s.size());

    for(int i = s.size() - 1; i >= 0; i--)
    {
        answer[i] = s.top();
        s.pop();
    }

    cout << answer;
}

int main()
{
    FASTIO

    cin >> n >> k;

    cin >> number;

    solution();

    return 0;
}
