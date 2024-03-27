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

int DP[100001];
int DP2[100001];

int solution(vector<int> sticker)
{
    int answer = 0;

    if (sticker.size() == 1)
        return sticker[0];

    DP[1] = sticker[0];
    for (int i = 2; i < sticker.size(); i++)
        DP[i] = max(DP[i - 1], DP[i - 2] + sticker[i - 1]);

    DP2[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++)
        DP2[i] = max(DP2[i - 1], DP2[i - 2] + sticker[i]);

    answer = max(DP[sticker.size() - 1], DP2[sticker.size() - 1]);

    return answer;
}