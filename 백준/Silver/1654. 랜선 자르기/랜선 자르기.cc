#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unsigned int N, K;					// N이 가지고 있는 랜선개수, K가 필요한 랜선개수
	unsigned int temp, Min, Max, Maxi = 0;
	unsigned int mid;
	unsigned int result = 0;
	unsigned int sum = 0;
	vector<unsigned int> length;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		length.push_back(temp);
		Maxi = max(Maxi, length[i]);
	}

	Min = 1;
	Max = Maxi;

	while (Min <= Max)
	{
		mid = (Min + Max) / 2;
		sum = 0;

		for (auto& Vec : length)
		{
			sum += Vec / mid;
		}

		if (sum >= K)							// sum >= K일 경우 길이가 짧거나 같다
		{
			result = max(result, sum);			// 개수가 나와도 더 큰 길이가 있는지 확인
			Min = mid + 1;
		}

		else									// sum < K일 경우 길이가 길다
		{
			Max = mid - 1;
		}
	}

	cout << Max;

	return 0;
}