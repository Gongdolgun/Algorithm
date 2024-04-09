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

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> coo(n + 1);

    for (auto& r : roads)    // 맵 초기화
    {
        coo[r[0]].push_back(r[1]);
        coo[r[1]].push_back(r[0]);
    }

    for(int i = 0 ; i < sources.size(); i++)
    {
        vector<bool> visited(n + 1, false);
        queue<pair<int, int>> q; // (현재 노드, 거리)
        q.push({sources[i], 0});
        visited[sources[i]] = true;
        bool found = false;

        while(!q.empty())
        {
            auto [cur_node, cnt] = q.front();
            q.pop();

            if(cur_node == destination)
            {
                answer.push_back(cnt);
                found = true;
                break;
            }

            for(int next_node : coo[cur_node])
            {
                if(!visited[next_node])
                {
                    visited[next_node] = true;
                    q.push({next_node, cnt + 1});
                }
            }
        }

        if (!found)
        {
            answer.push_back(-1);
        }
    }

    return answer;
}
