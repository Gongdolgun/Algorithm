#include <iostream>
#include <queue>
#include <cstring>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define MAX 301

using namespace std;

int n, m;
int arr[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void melt() {
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > 0) {
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
                        temp[i][j]++;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = max(0, arr[i][j] - temp[i][j]);
        }
    }
}

bool isSeparated() {
    memset(visited, false, sizeof(visited));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > 0 && !visited[i][j]) {
                count++;
                if (count > 1) return true; // 두 개 이상의 군집이 있으면 분리된 것

                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] > 0 && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    FASTIO

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int year = 0;
    while (true) {
        if (isSeparated()) {
            cout << year;
            return 0;
        }

        melt();
        year++;

        bool allMelted = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] > 0) {
                    allMelted = false;
                    break;
                }
            }
            if (!allMelted) break;
        }

        if (allMelted) {
            cout << 0;
            return 0;
        }
    }

    return 0;
}
