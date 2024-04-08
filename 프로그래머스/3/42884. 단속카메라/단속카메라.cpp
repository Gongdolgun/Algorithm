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
#define INF 987654321
#define ll long long

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), cmp);
    int camera = -30001;

    for(auto& r : routes)
    {
	    if(camera < r[0])
	    {
            camera = r[1];
            answer++;
	    }
    }

    cout << answer;

    return answer;
}