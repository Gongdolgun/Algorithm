#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int n, m, l;
int point[1000];
int target[1000];

void input(){
    cin >> n >> m >> l;
    for (int i = 0; i < m; i++) cin >> point[i];
    for (int i = 0; i < n; i++) cin >> target[i];
}

void solution() {
    for (int j = 0; j < n; j++) {
        int left = 0;
        int right = l;

        while (left <= right) {
            int mid = (left + right) / 2;
            int prev = 0; int cut = 0;

            for (int i = 0; i < m; i++) {
                if (point[i] - prev >= mid) {
                    prev = point[i];
                    cut++;
                }
            }

            //조각의 개수가 같고 마지막의 조각의 길이 또한 mid보다 커야하는데 작으면 right= mid -1 조건문으로 보냄
            if (target[j] == cut && l - prev < mid) {
                cut = target[j] - 1;
            }
            if (cut < target[j]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        cout << right << "\n";
    }

}

void solve(){
	input();
	solution();
}

int main() {

	solve();

	return 0;
}