#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>

using namespace std;
queue<int> que;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num;

	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		que.push(i);
	}
	
	while(que.size() > 1)
	{
		que.pop();
		que.push(que.front());
		que.pop();
		
	}

	cout << que.front();

	return 0;
}