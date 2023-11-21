#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define INF 987654321

using namespace std;

int n, s;
vector<int> nums;

void input()
{
	cin >> n >> s;
	nums.resize(n + 1);

	for (int i = 0; i < n; i++)
		cin >> nums[i];
}

void solution()
{
	// 2 pointer 알고리즘
	// start ~ end의 값이 s보다 작으면 end를 한칸 올림
	// start ~ end의 값이 s보다 크거나 같으면 start를 한칸 올림

	int start_pos = 0, end_pos = 0;
	int sum = nums[start_pos];
	int answer = INF;

	while (1)
	{
		if (sum < s)
		{
			end_pos++;
			sum += nums[end_pos];
		}
		else
		{
			answer = min(answer, end_pos - start_pos + 1);
			sum -= nums[start_pos];
			start_pos++;
		}

		if (end_pos == n || answer == 1)
			break;
	}

	if (answer == INF)
	{
		cout << 0;
		return;
	}

	cout << answer;
}

int main()
{
	input();
	solution();

	return 0;
}