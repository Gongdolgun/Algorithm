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

string a, b;
vector<int> nums;

void solution() {
    int answer = 0;

    sort(nums.begin(), nums.end());
    do
    {
        string strtmp;
        for(auto& N : nums)
            strtmp += to_string(N);

        if(stoi(strtmp) < stoi(b) && strtmp[0] != '0')
            answer = max(stoi(strtmp), answer);
    }
    while (next_permutation(nums.begin(),nums.end()));

    if(answer == 0)
    {
        cout << -1;
        return;
    }

    cout << answer;
}

int main()
{
    FASTIO

	cin >> a >> b;
    for(int i = 0; i < a.length(); i++)
        nums.push_back(a[i] - '0');

    solution();

    return 0;
}