#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
vector<char> alphabet;
vector<bool> check;

void input()
{
	cin >> n >> m;

	alphabet.resize(m);
	check.resize(m);

	for(int i = 0; i < m; i++)
		cin >> alphabet[i];
}

bool check_m(string str)
{
	int cnt = 0;

	for(int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			cnt++;
	}

	if (cnt >= str.length() - 1)
		return false;

	else if (cnt == 0)
		return false;

	else
		return true;
}

void dfs(int cnt, string str)
{
	string stmp = str;

	if (stmp.size() == n)
	{
		if(check_m(stmp))
			cout << stmp << '\n';
		return;
	}

	for(int i = cnt; i < alphabet.size(); i++)
	{
		if(check[i] == false)
		{
			check[i] = true;
			dfs(i+1, stmp + alphabet[i]);
			check[i] = false;
		}
	}
}

void solution()
{
	sort(alphabet.begin(), alphabet.end());

	dfs(0, "");
}

int main()
{
	input();
	solution();

	return 0;
}