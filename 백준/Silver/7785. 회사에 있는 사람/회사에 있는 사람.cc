#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	map<string, string, greater<>> data;
	string key;
	string value;
	int num;

	cin >> num;

	for(int i = 0; i < num; i++)
	{
		cin >> key >> value;

		auto dfind = data.find(key);

		if (dfind == data.end())
			data.insert(make_pair(key, value));

		else
			data.erase(key);
	}

	for(auto iter = data.begin(); iter != data.end(); ++iter)
	{
		cout << iter->first << '\n';
	}

	return 0;
}