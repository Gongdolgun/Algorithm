#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, temp;
	bool bIn = false;

	vector<int> data;
	vector<int> result;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		data.push_back(temp);
	}
	sort(data.begin(), data.end());

	cin >> m;

	for(int j = 0; j < m; j++)
	{
		cin >> temp;

		bIn = binary_search(data.begin(), data.end(), temp);
		result.push_back(bIn);
	}

	for(auto& Result : result)
		cout << Result << '\n';

	return 0;
}