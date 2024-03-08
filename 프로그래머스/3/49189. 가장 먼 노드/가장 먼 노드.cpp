#include <string>
#include <vector>
#include <queue>
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

vector<int> nodes[20001];
int visited[20001];

int solution(int n, vector<vector<int>> edge) {
    for (auto& e : edge) {
        nodes[e[0]].push_back(e[1]);
        nodes[e[1]].push_back(e[0]);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : nodes[curr]) {
            if (!visited[next]) {
                visited[next] = visited[curr] + 1;
                q.push(next);
            }
        }
    }

    int maxDist = 0;
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (maxDist < visited[i]) {
            maxDist = visited[i];
            answer = 1;
        } else if (maxDist == visited[i]) {
            answer++;
        }
    }

    return answer;
}

int main() {
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge;
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        edge.push_back({ start, end });
    }

    cout << solution(n, edge);

    return 0;
}
