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
#include <unordered_map>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

int xpos[4] = { 1, 0, -1, 0 };
int ypos[4] = { 0, 1, 0, -1 };

vector<vector<bool>> check;

int solution(vector<vector<int>> land) {
    int answer = 0;
    check.resize(land.size(), vector<bool>(land[0].size()));

    vector<int> columnSum(land[0].size(), 0); // 각 열별 석유 시추량 합계를 저장할 벡터

    for(int i = 0; i < land.size(); i++) {
        for(int j = 0; j < land[0].size(); j++) {
            if(land[i][j] == 1 && !check[i][j]) {
                queue<pair<int, int>> q;
                q.push({ i, j });
                check[i][j] = true;
                int cnt = 1;
                int left = j, right = j;

                while (!q.empty()) {
                    int cur_x = q.front().first;
                    int cur_y = q.front().second;
                    q.pop();

                    for(int k = 0; k < 4; k++) {
                        int next_x = cur_x + xpos[k];
                        int next_y = cur_y + ypos[k];

                        if(next_x < 0 || next_x >= land.size() || next_y < 0 || next_y >= land[0].size())
                            continue;

                        if(land[next_x][next_y] == 0 || check[next_x][next_y])
                            continue;

                        check[next_x][next_y] = true;
                        cnt++;
                        q.push({ next_x, next_y });
                        left = min(left, next_y);
                        right = max(right, next_y);
                    }
                }

                for(int k = left; k <= right; k++) {
                    columnSum[k] += cnt; // 해당 영역이 포함하는 열에 대해 석유 시추량을 업데이트
                }
            }
        }
    }

    answer = *max_element(columnSum.begin(), columnSum.end()); // 최대 석유 시추량을 찾음

    cout << answer;
    return answer;
}
