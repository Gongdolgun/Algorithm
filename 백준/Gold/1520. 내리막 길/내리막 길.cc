#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<vector<int>> map;
vector<vector<int>> dp;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int DFS(int x, int y) {
    // 목적지에 도달한 경우
    if (x == n - 1 && y == m - 1) return 1;
    // 이미 방문한 경우
    if (dp[x][y] != -1) return dp[x][y];
    
    dp[x][y] = 0; // 초기화
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (map[nx][ny] < map[x][y]) {
                dp[x][y] += DFS(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    dp.resize(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> map[i][j];

    cout << DFS(0, 0) << '\n';

    return 0;
}
