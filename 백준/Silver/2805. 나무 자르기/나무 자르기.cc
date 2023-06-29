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

	long long N, K;					// N이 가지고 있는 랜선개수, K가 필요한 랜선개수
	long long temp, Min, Max, Maxi = 0;
	long long mid;
	long long result = 0;
	long long sum = 0;
	vector < long long > length;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		length.push_back(temp);
		Maxi = max(Maxi, length[i]);
	}

	Min = 0;
	Max = Maxi;

	while (Min <= Max)
	{
		mid = (Min + Max) / 2;
		sum = 0;

		for (auto& Vec : length)
		{
			long long num = Vec - mid;
			if(num > 0)
				sum += num;
		}

		if (sum > K)							// sum >= K일 경우 길이가 짧거나 같다
		{
			result = mid;
			Min = mid + 1;
		}

		else if (sum < K)								// sum < K일 경우 길이가 길다
		{
			Max = mid - 1;
		}

		else
		{
			result = mid;
			break;
		}

	}

	cout << result;

	return 0;
}