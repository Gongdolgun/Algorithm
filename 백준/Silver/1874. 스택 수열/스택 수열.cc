#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<char> result;
	vector<int> vec;
	stack<int> st;
	int num;
	int temp;
	int vecNum = 0;

	cin >> num;

	for(int i = 0; i < num; i++)
	{
		cin >> temp;

		vec.push_back(temp);
	}

	for(int j = 1; j <= vec.size(); j++)
	{
		if (j == 1)
		{
			st.push(j);
			result.push_back('+');
			continue;
		}

		if(st.top() == vec[vecNum])
		{
			while(1)
			{
				if (st.empty() || st.top() != vec[vecNum])
					break;

				st.pop();
				result.push_back('-');

				vecNum++;
			}
		}

		st.push(j);
		result.push_back('+');
	}

	while (1)
	{
		if (st.top() != vec[vecNum])
			break;

		st.pop();
		result.push_back('-');

		if (st.empty())
			break;

		vecNum++;
	}

	if (!st.empty())
		cout << "NO";
	else
	{
		for (auto& Result : result)
			cout << Result << '\n';
	}
	
	return 0;
}