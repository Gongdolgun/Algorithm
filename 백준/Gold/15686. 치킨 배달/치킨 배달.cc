#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> vec;
vector<pair<int, int>> chicken_pos;
vector<pair<int, int>> Homes;

void input()
{
	cin >> n >> m;

	vec.resize(n + 1, vector<int>(n + 1));

	for(int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> vec[i][j];
			if (vec[i][j] == 2)
				chicken_pos.push_back(make_pair(i, j));

			else if(vec[i][j] == 1)
				Homes.push_back(make_pair(i, j));
		}
	}
}

int calculated_dist(pair<int, int> home_pos, pair<int, int> chicken_pos)
{
	return abs(home_pos.first - chicken_pos.first) + abs(home_pos.second - chicken_pos.second);
}

void solution()
{
    int answer = 1e9;
    vector<bool> isSelected(chicken_pos.size(), false);
    for(int i = 0; i < m; i++)
        isSelected[i] = true;

    do
    {
        int answertmp = 0;
        for(int i = 0; i < Homes.size(); i++)
        {
            int tmp = 1e9;
            for(int j = 0; j < chicken_pos.size(); j++)
            {
                if(isSelected[j])
                    tmp = min(calculated_dist(Homes[i], chicken_pos[j]), tmp);
            }
            answertmp += tmp;
        }
        answer = min(answertmp, answer);
    }
    while(prev_permutation(isSelected.begin(), isSelected.end()));

    cout << answer;
}


int main()
{
	input();
	solution();

	return 0;
}