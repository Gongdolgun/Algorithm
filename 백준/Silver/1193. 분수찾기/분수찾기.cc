#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> vec1;
	vector<int> vec2;

	int num1 = 1;
	int num2 = 1;

	bool bVec1 = false;
	bool bVec2 = false;

	bool v1 = false;
	bool v2 = true;

	int a;

	cin >> a;

	while (1)
	{
		if(!v1)
		{
			for (int p = num1; p > 0; p--)
			{
				if (vec1.size() == a)
				{
					bVec1 = true;
					break;
				}

				vec1.push_back(p);
			}
		}

		if (v1)
		{
			for (int p = 1; p <= num1; p++)
			{
				if (vec1.size() == a)
				{
					bVec1 = true;
					break;
				}

				vec1.push_back(p);
			}
		}

		v1 = !v1;

		if (bVec1)
			break;

		num1++;
	}

	while (1)
	{
		if (!v2)
		{
			for (int p = num2; p > 0; p--)
			{
				if (vec2.size() == a)
				{
					bVec2 = true;
					break;
				}

				vec2.push_back(p);
			}
		}

		if (v2)
		{
			for (int p = 1; p <= num2; p++)
			{
				if (vec2.size() == a)
				{
					bVec2 = true;
					break;
				}

				vec2.push_back(p);
			}
		}

		v2 = !v2;

		if (bVec2)
			break;

		num2++;
	}

	 cout << vec1[a-1] << "/" << vec2[a-1];

	return 0;
}