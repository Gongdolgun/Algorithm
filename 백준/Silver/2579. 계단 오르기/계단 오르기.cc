#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int N;
int DP[300];
int arr[300];

void input()
{
    cin >> N;

	for(int i = 1; i <= N; i++)
	{
        cin >> arr[i];
	}
}

void solution()
{
	// 1. N번째 계단은 무조건 밟아야 한다.
    // 2. 3개 이상의 연속된 계단은 밟지 못한다.

    // DP[N-3] + arr[N-1] + arr[N] or DP[N-2] + arr[N] 둘중 하나가 최대값.
    // N은 최소 3개 이상부터 계산하면 됨

    DP[0] = arr[0] = 0;
    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];
    DP[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

    for (int i = 4; i <= N; i++)
    {
        DP[i] = max(DP[i - 2] + arr[i], DP[i - 3] + arr[i - 1] + arr[i]);
    }

    cout << DP[N];
}

void solve ()
{
    input();
    solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}