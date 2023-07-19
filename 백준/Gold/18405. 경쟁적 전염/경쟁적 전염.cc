#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Virus {
    int x, y, num, time;
    bool operator<(const Virus& other) const {
        if (time == other.time) {
            return num > other.num;
        }
        return time > other.time;
    }
};

int N, K;
vector<vector<int>> arr;
int S, X, Y;

void input() {
    cin >> N >> K;
    arr.resize(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> S >> X >> Y;
}

void solution() {
    priority_queue<Virus> pq;
    // 상, 하, 좌, 우 이동에 대한 좌표 변화량
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // 초기 바이러스 위치를 우선순위 큐에 넣음
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] != 0) {
                pq.push({i, j, arr[i][j], 0});
            }
        }
    }

    while (!pq.empty()) {
        Virus cur = pq.top();
        pq.pop();

        // 시간이 S 초과되면 종료
        if (cur.time == S) {
            break;
        }

        // 상하좌우로 전파
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            // 범위를 벗어나거나 이미 방문한 곳이면 건너뜀
            if (nx <= 0 || nx > N || ny <= 0 || ny > N || arr[nx][ny] != 0) {
                continue;
            }

            // 바이러스 전파
            arr[nx][ny] = cur.num;
            pq.push({nx, ny, cur.num, cur.time + 1});
        }
    }

    cout << arr[X][Y] << endl;
}

void solve() {
    input();
    solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}