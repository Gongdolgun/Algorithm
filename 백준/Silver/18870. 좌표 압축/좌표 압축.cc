#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n;
vector<int> vec;
vector<int> vtmp;

void input()
{
	cin >> n;
	vec.resize(n);
	vtmp.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		vtmp[i] = vec[i];
	}
}

void solution()
{
	sort(vtmp.begin(), vtmp.end());

	vtmp.erase(unique(vtmp.begin(), vtmp.end()), vtmp.end());

	for (int i = 0; i < vec.size(); i++)
		cout << lower_bound(vtmp.begin(), vtmp.end(), vec[i]) - vtmp.begin() << ' ';

}

int main()
{
	input();
	solution();

	return 0;
}