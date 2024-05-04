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
#define INF 98765421
#define ll long long

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for(long long i = left; i <= right; i++) {
        ll row = i / n; // 현재 행
        ll col = i % n; // 현재 열
        answer.push_back(max(row, col) + 1);
    }

    return answer;
}
