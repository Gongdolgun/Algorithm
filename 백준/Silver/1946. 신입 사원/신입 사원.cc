#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solution(vector<pair<int, int>> grades)
{
	sort(grades.begin(), grades.end());

	int maxGrade = 987654321;
	int cnt = 0;
	for(int i = 0; i < grades.size(); i++)
	{
		if(maxGrade > grades[i].second)
		{
			cnt++;
			maxGrade = grades[i].second;
		}
	}

	cout << cnt << endl;
}

int main()
{
	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		int b;
		cin >> b;

		vector<pair<int, int>> grades;

		for(int j = 0; j < b; j++)
		{
			int x, y;
			cin >> x >> y;
			grades.push_back(make_pair(x, y));
		}
		solution(grades);
	}

	return 0;
}