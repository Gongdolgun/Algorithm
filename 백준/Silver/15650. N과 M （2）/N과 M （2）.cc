#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int n, m;
int arr[10] = {0, };
bool check[10] = {0, };

void func(int god)
{	
	if (god == m)
	{
		for (int i = 0; i < m - 1; i++) 
		{
			if (arr[i] > arr[i + 1])
				return;
		}

		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{	
		if (!check[i])
		{
			check[i] = true;
			arr[god] = i;
			func(god + 1);
			check[i] = false;
			if (god == 0)
				check[i] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	func(0);

	return 0;
}