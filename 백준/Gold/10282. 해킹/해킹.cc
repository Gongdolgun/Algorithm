#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    // 테스트 케이스 수 입력
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int nodes, dependency, snode;
        cin >> nodes >> dependency >> snode;

        // 그래프 초기화
        vector<vector<pair<int, int>>> graph(nodes + 1);

        // 그래프 입력 (간선 방향 주의)
        for (int j = 0; j < dependency; j++) {
            int a, b, price;
            cin >> a >> b >> price;
            graph[b].push_back(make_pair(price, a)); // b에서 a로 가는 방향
        }

        // 다익스트라 알고리즘
        vector<int> dist(nodes + 1, numeric_limits<int>::max()); // 거리 초기화
        vector<bool> visited(nodes + 1, false); // 방문 여부
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[snode] = 0; // 시작 노드의 거리 0으로 초기화
        pq.push(make_pair(0, snode)); // (거리, 노드)

        while (!pq.empty()) {
            int current_dist = pq.top().first;
            int current_node = pq.top().second;
            pq.pop();

            if (visited[current_node]) continue; // 이미 방문한 노드
            visited[current_node] = true;

            for (const auto& edge : graph[current_node]) {
                int weight = edge.first;
                int next_node = edge.second;

                if (dist[next_node] > current_dist + weight) {
                    dist[next_node] = current_dist + weight;
                    pq.push(make_pair(dist[next_node], next_node));
                }
            }
        }

        int count = 0;
        int max_time = 0;

        for (int i = 1; i <= nodes; i++) {
            if (dist[i] != numeric_limits<int>::max()) {
                count++;
                max_time = max(max_time, dist[i]);
            }
        }

        cout << count << ' ' << max_time << '\n';
    }

    return 0;
}
