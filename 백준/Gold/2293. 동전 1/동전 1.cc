#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, K;
int cnt = 0;
vector<int> money(102);
vector<int> dp(10001);

void input() {
    cin >> N >> K;

    for(int i = 1;i <= N; i++)
        cin >> money[i];
}

void solution() {

    // K가 0일 때 경우의 수 1가지
    // 만약 K = 9일때 1, 2, 5의 조합에서 5가 들어간다면 1, 2끼리 5를 만들 수 있는 조합을 빼줘야 한다.
    // 그래서 dp[9] + dp[4] 가 되어야 한다.
    dp[0] = 1;                                      
    for (int i = 1; i <= N; i++) { 
        for (int j = money[i]; j <= K; j++) {
            dp[j] = dp[j] + dp[j - money[i]];
        }
    }

    cout << dp[K] << endl;
    
}

void solve() {
    input();
    solution();
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}