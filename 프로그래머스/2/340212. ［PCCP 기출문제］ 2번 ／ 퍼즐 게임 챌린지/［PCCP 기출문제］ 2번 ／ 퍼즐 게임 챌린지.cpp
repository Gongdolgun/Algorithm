#include <bits/stdc++.h>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

// 틀리는 회수 = diff - level
// 틀렸을 때 드는 시간 = times[i] + times[i - 1]
// 총 드는 시간 = (diff - level) * (times[i] + times[i - 1]) + times[i];

bool possible(int level, vector<int>& diffs, vector<int>& times, ll limit){

    ll current_time = 0;
    ll prev_time = 0;

    for(int i = 0; i<diffs.size(); i++){
        if(level >= diffs[i]){
            current_time += times[i];
        }else{
            ll repeat = diffs[i] - level;
            current_time += times[i] + (times[i] + prev_time) * repeat;
        }
        prev_time = times[i];
        if(current_time > limit) return false;
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {

    int l = 1;
    int r = 200000;
    int ans = INT_MAX;

    while (l <= r){
        int mid = (l + r)/2;
        if(possible(mid, diffs, times, limit)){
            r = mid - 1;
            ans = min(mid, ans);
        }else{
            l = mid + 1;
        }

    }
    return ans;
}