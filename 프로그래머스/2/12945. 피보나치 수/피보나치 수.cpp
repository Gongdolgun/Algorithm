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

int arr[100000];

int solution(int n) {
    int answer = 0;

    arr[1] = 1;

    for(int i = 2; i <= n; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1234567;

    answer = arr[n];

    cout << answer;

    return answer;
}

int main()
{
    FASTIO

    int n = 0;

    cin >> n;
    solution(n);

    return 0;
}