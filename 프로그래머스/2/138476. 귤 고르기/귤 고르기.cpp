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
#include <thread>
#include <mutex>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    vector<int> v(10000001);

    for (auto& tan : tangerine)
        v[tan]++;

    sort(v.begin(), v.end(), greater<>());

    int cnt = 0;
    int prev_cnt = 0;
    for(auto& V : v)
    {
        prev_cnt = cnt;
        cnt += V;

        if (k > cnt)
            answer++;

        else if( k == cnt)
        {
            answer++;
            return answer;
        }

        else
            break;
    }

    if (prev_cnt < k)
        answer++;

    return answer;
}