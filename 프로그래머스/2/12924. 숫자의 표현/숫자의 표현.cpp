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

int solution(int n) {
    if (n == 1)
        return 1;

    int answer = 0;
	vector<int> nums(n);
	int l = 0, r = 1, value = 0;

    for (int i = 0; i < n; i++)
        nums[i] = i + 1;

    value = nums[l] + nums[r];

    while(r < n)
    {
        if (value == n)
        {
            answer++;
            r++;

            if(r < n)
				value += nums[r];
        }

        else if (value < n)
        {
            r++;
            value += nums[r];
        }

        else if (value > n)
        {
            value -= nums[l];
            l++;
        }
    }

    cout << answer;

    return answer;
}

int main()
{
    FASTIO

    int n = 0;

    cin >> n;
    solution(n);

    return 0;
}