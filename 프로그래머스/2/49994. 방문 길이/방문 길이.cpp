#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <bitset>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <set>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

set<pair<pair<int, int>, pair<int, int>>> visited; // 이동 경로를 저장할 집합
pair<int, int> pos = {5, 5}; // 초기 위치

bool isValid(int x, int y) { // 격자 범위 체크
    return x >= 0 && x < 11 && y >= 0 && y < 11;
}

int solution(string dirs) {
    int answer = 0;

    for (auto& dir : dirs) {
        int x = pos.first, y = pos.second;
        switch (dir) {
            case 'U': y++; break;
            case 'D': y--; break;
            case 'R': x++; break;
            case 'L': x--; break;
        }

        if (isValid(x, y)) { // 이동하려는 위치가 유효한 경우
            pair<pair<int, int>, pair<int, int>> path1 = make_pair(make_pair(pos.first, pos.second), make_pair(x, y));
            pair<pair<int, int>, pair<int, int>> path2 = make_pair(make_pair(x, y), make_pair(pos.first, pos.second));
            // 이동 경로가 처음이라면
            if (visited.find(path1) == visited.end() && visited.find(path2) == visited.end()) {
                visited.insert(path1); // 경로 저장
                answer++; // 방문 길이 증가
            }
            pos = make_pair(x, y); // 위치 업데이트
        }
    }

    return answer;
}