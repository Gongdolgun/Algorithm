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

int n, m, s_node, e_node;
vector<vector<pair<int, int>>> datas;
int prices[1001];
bool visited[1001];

struct Compare {
    bool operator()(pair<int, pair<int, int>> const& a, pair<int, pair<int, int>> const& b) {
        return a.first > b.first;  // 첫 번째 원소가 두 번째 원소보다 큰 경우 true 반환
    }
};

void solution()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;
    for (int i = 0; i < datas[s_node].size(); i++)
    {
        int price = datas[s_node][i].second;
        int s = s_node;
        int e = datas[s_node][i].first;

        pq.push(make_pair(price, make_pair(s, e)));
    }

    while (!pq.empty())
    {
        int prev_node = pq.top().second.first;                     // 출발지
        int curr_node = pq.top().second.second;                    // 목적지
        int curr_price = pq.top().first;                           // 가격
        pq.pop();

        if(visited[curr_node] == true)
            continue;

        visited[curr_node] = true;
        prices[curr_node] = curr_price;

        for (int i = 0; i < datas[curr_node].size(); i++)
        {
            int next_node = datas[curr_node][i].first;
            int next_price = datas[curr_node][i].second;

            if(!visited[next_node])
                pq.push(make_pair(prices[curr_node] + next_price, make_pair(curr_node, next_node)));
        }
    }

    cout << prices[e_node];
}

int main()
{
    FASTIO

    cin >> n >> m;
    fill(prices, prices + 1001, INF);
    datas.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int s, e, price;
        cin >> s >> e >> price;

        datas[s].push_back(make_pair(e, price));
    }

    cin >> s_node >> e_node;

    prices[s_node] = 0;

    solution();

    return 0;
}
