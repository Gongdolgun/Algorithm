#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <bitset>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

int is_P(int left, int right, string str)
{
	while(1)
	{
        if (left < 0 || right >= str.length())
            break;

        if (str[left] != str[right])
            break;

        left--;
        right++;
	}
    left++;
    right--;

    return right - left + 1;
}

int solution(string s)
{
    int answer = 0;

    for(int i = 0; i < s.length(); i++)
    {
    	answer = max(answer, is_P(i, i, s));
    	answer = max(answer, is_P(i - 1, i, s));
    }

    cout << answer;
    return answer;
}