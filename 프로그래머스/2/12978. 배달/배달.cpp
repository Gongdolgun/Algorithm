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

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

vector<vector<pair<int, int>>> coo (51);
vector<int> cost(51, INF);

void dijkstra ()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, 1));               // {cost, next}

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();
        cost[1] = 0;;

        for(int i = 0; i < coo[cur].size(); i++)
        {
            int next = coo[cur][i].first;
            int ncost = coo[cur][i].second;
            if (cost[next] > cost[cur] + ncost)
            {
                cost[next] = cost[cur] + ncost;
                pq.push(make_pair(ncost, next));
            }
        }

    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i = 0; i < road.size(); i++)
    {
        coo[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        coo[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }

    dijkstra();

    for(int i = 1; i <= N; i++)
    {
        if (cost[i] <= K)
            answer++;
    }

    return answer;
}