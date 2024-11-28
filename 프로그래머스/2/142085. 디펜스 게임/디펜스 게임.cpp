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
#include <cstring>
#include <numeric>
#include <unordered_map>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 0; i < enemy.size(); i++)
    {
        pq.push(enemy[i]);

        if(pq.size() <= k)
        {
            answer++;
            continue;
        }

        n -= pq.top();
        pq.pop();

    	if (n < 0)
			break;

        answer++;
    }

    return answer;
}