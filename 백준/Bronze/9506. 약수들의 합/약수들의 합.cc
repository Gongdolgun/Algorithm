#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a;
	int sum = 0;

	vector<int> num;
	vector<int> MNum;

	while (1)
	{
		cin >> a;

		if (a == -1)
			break;

		num.push_back(a);
	}

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 1; j < num[i]; j++)
		{
			if (num[i] % j == 0)
				MNum.push_back(j);
		}

		for (int k = 0; k < MNum.size(); k++)
		{
			sum += MNum[k];
		}

		if (sum == num[i])
		{
			cout << num[i] << " = ";

			for (int r = 0; r < MNum.size(); r++)
			{
				cout << MNum[r];

				if (r != MNum.size() - 1)
					cout << " + ";

				else
					cout << "\n";
			}
		}

		else
			cout << num[i] << " is NOT perfect.\n";

		sum = 0;
		MNum.clear();
	}

	return 0;
}