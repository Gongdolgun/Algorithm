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

// enroll - 사원 이름
// referral - 추천인 (없을 경우 '-')
// seller - 판매인
// amount - 판매량

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    unordered_map<string, pair<string, int>> um;
    for(int i = 0; i < enroll.size(); i++)
    {
        um[enroll[i]] = make_pair(referral[i], 0);
    }

    for(int i = 0; i < seller.size(); i++)
    {
        string curr_person = seller[i];
        int tmp = amount[i] * 100;

	    while(1)
	    {
            if (curr_person == "-" || tmp == 0)
                break;

            um[curr_person].second += (tmp - floor(tmp * 0.1));
            tmp = tmp * 0.1;

            curr_person = um[curr_person].first;
	    }
    }

    for (auto& en : enroll)
        answer.push_back(um[en].second);

    return answer;
}