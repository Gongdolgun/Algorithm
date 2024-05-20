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

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

string n;
int m;
vector<int> broken_num(10);

bool check(int num)
{
	string str = to_string(num);
	for(int i = 0; i < str.length(); i++)
	{
		if (broken_num[str[i] - '0'] == 1)
			return false;
	}

	return true;
}

void solution()
{
	if(n == "100")
	{
		cout << 0;
		return;
	}

	int cnt = abs(stoi(n) - 100);	//첫번째 cnt

	for(int i = 0; i < 1000000; i++)
	{
		if(check(i) == true)
		{
			int cnt2 = abs(stoi(n) - i) + to_string(i).length();
			cnt = min(cnt, cnt2);
		}
	}

	cout << cnt;

}

int main() {
	FASTIO

	cin >> n >> m;
	for (int i = 0; i < m; i++)		// 고장난 번호
	{
		int tmp;
		cin >> tmp;
		broken_num[tmp] = 1;
	}
	solution();

    return 0;
}
