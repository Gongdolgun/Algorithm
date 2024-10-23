#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421

using namespace std;

int arr[3][3] = { {1, 1, 1}, {5, 1, 1}, {25, 5, 1} };
unordered_map<string, int> m;
int result = INF;

void DFS(vector<int> picks, vector<string>& minerals, int location, int inResult)
{
    // 광물을 끝까지 캤거나, 곡괭이를 다 썼을 때
    if (location >= minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
    {
        result = min(result, inResult);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (picks[i] != 0)
        {
            picks[i]--; // 곡괭이 사용
            int tmp = inResult; // 현재 결과값 복사

            // 곡괭이로 캘 수 있는 광물 5개까지 처리
            for (int j = location; j < location + 5; j++)
            {
                if (j >= minerals.size())
                    break;

                tmp += arr[i][m[minerals[j]]]; // 광물에 따른 비용 추가
            }

            DFS(picks, minerals, location + 5, tmp); // 다음 위치로 재귀 호출
            picks[i]++; // 곡괭이 복구
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    m["diamond"] = 0;
    m["iron"] = 1;
    m["stone"] = 2;

    DFS(picks, minerals, 0, 0);

    return result;
}

int main()
{
    FASTIO

    cout << solution({0, 1, 1}, { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" });
}
