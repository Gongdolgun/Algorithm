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
#define INF 9999999999
#define ll long long

using namespace std;

int n;
vector<ll> nums;

void solution()
{
    sort(nums.begin(), nums.end());
    ll left = 0, right = n - 1;
    pair<int, int> answer;
    ll result = INF;

    while(left < right)
    {
        ll sum = nums[left] + nums[right];
        if(abs(sum) < abs(result))
        {
            result = sum;
            answer = make_pair(nums[left], nums[right]);
        }

        if (result == 0)
            break;

        if(sum > 0)
            right--;

        else
            left++;
    }

    cout << answer.first << ' ' << answer.second;
}

int main()
{
    FASTIO

	cin >> n;
    nums.resize(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    solution();

    return 0;
}