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

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.begin(), dungeons.end());

    do
    {
        int prd = k;
        int cnt = 0;

        for(int i = 0; i < dungeons.size(); i++)
        {
	        if(dungeons[i][0] <= prd)
	        {
                prd -= dungeons[i][1];
                cnt++;
	        }
        }

        answer = max(answer, cnt);

    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}