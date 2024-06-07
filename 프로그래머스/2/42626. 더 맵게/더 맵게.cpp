#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq; // 최소 힙 사용
    for (auto& s : scoville)
        pq.push(s);

    while (pq.size() > 1 && pq.top() < K) { // 우선순위 큐의 최상단 원소가 K 미만일 때 반복
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int mixed = first + (second * 2); // 두 스코빌 지수를 섞음
        pq.push(mixed); // 섞은 스코빌 지수를 다시 우선순위 큐에 추가

        answer++; // 섞은 횟수 증가
    }

    if (pq.top() < K) // 모든 스코빌 지수를 K 이상으로 만들지 못한 경우
        return -1;

    return answer;
}
