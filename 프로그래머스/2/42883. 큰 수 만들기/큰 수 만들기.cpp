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
#include <cstring>
#include <numeric>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size() - k; // 최종 문자열 길이
    int start = 0;

    for (int i = 0; i < len; i++) {
        char maxChar = '0';
        int maxIndex = start;

        // 현재 위치에서 k+1 범위 내에서 가장 큰 숫자 찾기
        for (int j = start; j <= k + i; j++) {
            if (number[j] > maxChar) {
                maxChar = number[j];
                maxIndex = j;
            }
        }

        answer += maxChar; // 가장 큰 숫자를 결과 문자열에 추가
        start = maxIndex + 1; // 다음 시작 지점 이동
    }

    return answer;
}
