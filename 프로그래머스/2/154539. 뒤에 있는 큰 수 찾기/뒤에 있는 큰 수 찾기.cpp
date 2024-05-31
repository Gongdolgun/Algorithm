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

using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n, -1); // 기본값으로 -1을 할당
    stack<int> st; // 인덱스를 저장할 스택

    for (int i = 0; i < n; i++) {
        // 스택이 비어있지 않고, 현재 숫자가 스택의 top에 있는 숫자보다 큰 경우
        while (!st.empty() && numbers[i] > numbers[st.top()]) {
            answer[st.top()] = numbers[i]; // 답을 업데이트
            st.pop(); // 처리된 인덱스는 스택에서 제거
        }
        st.push(i); // 현재 인덱스를 스택에 추가
    }

    // 스택에 남은 인덱스는 -1로 이미 초기화되어 있으므로 추가 처리 필요 없음

    return answer;
}