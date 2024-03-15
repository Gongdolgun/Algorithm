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
#define INF 9999999999
#define ll long long

using namespace std;

int n;
int arr[1001];

void solution()
{
    sort(arr, arr + n);

    //결과값 구하기
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > res) {
            break;
        }
        res += arr[i];
    }

    //출력
    cout << res;
}

int main()
{
    FASTIO

	cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    solution();

    return 0;
}