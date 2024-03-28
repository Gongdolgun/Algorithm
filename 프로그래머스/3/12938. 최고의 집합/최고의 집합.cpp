#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <bitset>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

int DP[100001];
int DP2[100001];

vector<int> solution(int n, int s) {
    vector<int> answer;

    // s를 n으로 나눈 몫이 0이라면, 각 원소가 자연수가 되는 집합을 만들 수 없음
    if (s / n == 0)
        return { -1 };

    // s를 n으로 나눈 몫을 기준으로 집합의 초기 값을 설정
    for (int i = 0; i < n; i++) {
        answer.push_back(s / n);
    }

    // s를 n으로 나눈 나머지를 각 원소에 균등하게 분배
    for (int i = 0; i < s % n; i++) {
        answer[i]++;
    }

    sort(answer.begin(), answer.end());

    return answer;
}