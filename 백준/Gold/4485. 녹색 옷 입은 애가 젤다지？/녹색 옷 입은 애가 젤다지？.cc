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

int xpos[4] = { 1, 0, -1, 0 };
int ypos[4] = { 0, 1, 0, -1 };

int solution(const vector<vector<int>>& coo, int n) {
    vector<vector<int>> cost(n, vector<int>(n, INF));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    pq.push({ coo[0][0], {0, 0} });
    cost[0][0] = coo[0][0];

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        pq.pop();

        if (cost[curX][curY] < curCost) continue;

        for (int i = 0; i < 4; i++) {
            int nx = curX + xpos[i];
            int ny = curY + ypos[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            int nextCost = curCost + coo[nx][ny];
            if (cost[nx][ny] > nextCost) {
                cost[nx][ny] = nextCost;
                pq.push({ nextCost, {nx, ny} });
            }
        }
    }

    return cost[n - 1][n - 1];
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);

    int cnt = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<vector<int>> coo(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> coo[i][j];

        cout << "Problem " << cnt << ": " << solution(coo, n) << '\n';
        cnt++;
    }

    return 0;
}
