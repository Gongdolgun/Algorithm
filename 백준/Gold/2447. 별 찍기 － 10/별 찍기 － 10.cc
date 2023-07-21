#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;
char arr[2200][2200];

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
	    for(int j =1; j <= N; j++)
	    {
            arr[i][j] = '*';
	    }
    }
}

void solution(int num, int start_H, int end_H, int start_Y, int end_Y) {

    if (num == 1)
        return;

    int tmp = num / 3;

    for(int i = start_H + tmp; i <= end_H - tmp; i++)
    {
        for(int  j = start_Y + tmp; j <= end_Y - tmp; j++)
        {
            arr[i][j] = ' ';
        }
    }

    solution(tmp, start_H, start_H + tmp - 1, start_Y, start_Y + tmp - 1);
    solution(tmp, start_H, start_H + tmp - 1, start_Y + tmp, start_Y + tmp * 2 - 1);
    solution(tmp, start_H, start_H + tmp - 1, start_Y + tmp * 2, start_Y + tmp * 3 - 1);

    solution(tmp, start_H + tmp, start_H + (tmp * 2) - 1, start_Y, start_Y + tmp - 1);
    solution(tmp, start_H + tmp, start_H + (tmp * 2) - 1, start_Y + tmp * 2, start_Y + tmp * 3 - 1);

    solution(tmp, start_H + tmp * 2, start_H + (tmp * 3) -1, start_Y, start_Y + tmp - 1);
    solution(tmp, start_H + tmp * 2, start_H + (tmp * 3) -1, start_Y + tmp, start_Y + tmp * 2 - 1);
    solution(tmp, start_H + tmp * 2, start_H + (tmp * 3) -1, start_Y + tmp * 2, start_Y + tmp * 3 - 1);

}

void solve() {
    input();
    solution(N, 1, N, 1, N);

    for(int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << arr[i][j];

        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}