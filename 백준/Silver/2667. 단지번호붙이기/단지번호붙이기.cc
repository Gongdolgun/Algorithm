#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int arr[700][700];
bool check[700][700];
int n;
int tmp;

int x_pos[4] = { 1, 0, -1, 0 };
int y_pos[4] = { 0, 1, 0, -1 };

void DFS(int x, int y)
{
    check[x][y] = true;
    tmp++;

    for(int i = 0; i < 4; i++)
    {
        int next_x = x + x_pos[i];
        int next_y = y + y_pos[i];

        if(next_x < 0 || next_x > n || next_y < 0 || next_y > n)
            continue;

        if(check[next_x][next_y] == true)
            continue;

        if(arr[next_x][next_y] == 0)
            continue;

        DFS(next_x, next_y);
    }
}

int main()
{
    cin >> n;
    vector<int> answer;

    vector<string> s(n);

    for (int i = 0; i < n; i++)
    	cin >> s[i];

    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < n; j++)
	    {
            arr[i][j] = s[i][j] - '0';
	    }
    }

    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < n; j++)
	    {
		    if(arr[i][j] == 1 && check[i][j] == false)
		    {
                DFS(i, j);
                answer.push_back(tmp);
                tmp = 0;
		    }
	    }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}