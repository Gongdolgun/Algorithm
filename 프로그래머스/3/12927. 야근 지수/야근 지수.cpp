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

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;

    for (auto& W : works)
        pq.push(W);

    while(1)
    {
        if (n <= 0 || pq.empty())
            break;

        int tmp = pq.top();
        pq.pop();

        tmp--;
        n--;

        if(tmp)
			pq.push(tmp);
    }

    if (!pq.empty())
    {
        while (!pq.empty())
        {
            answer += pq.top() * pq.top();
            pq.pop();
        }
    }

    return answer;
}