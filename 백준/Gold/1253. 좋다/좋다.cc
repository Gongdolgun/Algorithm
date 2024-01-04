#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	int count = 0;

	for(int i = 0; i < N; i++)
	{
		int Val = arr[i];
		int left = 0;
		int right = N-1;

		while(left < right)
		{
			if(left == i)
			{
				left++;
				continue;
			}

			else if(right == i)
			{
				right--;
				continue;
			}

			int sum = arr[left] + arr[right];

			if(sum == Val)
			{
				count++;
				break;
			}
			else if(sum < Val)
			{
				left++;
				continue;
			}

			else if(sum > Val)
			{
				right--;
				continue;
			}
		}
	}

	cout << count;
}