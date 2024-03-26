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

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

int countOne(int n) {
    int ret = 0;
    // n의 이진수에서 1의 개수 세기
    for (int i = 0; i < 31; i++) {
        if (n & 0x01 << i)
            ret++;
    }
    return ret;
}

int solution(int n) {
    int cnt = countOne(n);
    n++;

    while(cnt != countOne(n))
        n++;

    return n;
}

int main()
{
    FASTIO

	int n;
    cin >> n;

    cout << solution(n);

    return 0;
}