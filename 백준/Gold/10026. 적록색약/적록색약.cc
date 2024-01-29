#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool check[101][101];
vector<string> str;
int n;
int tmp;

int x_pos[4] = { 1, 0, -1, 0 };
int y_pos[4] = { 0, 1, 0, -1 };

void DFS(int x, int y, char alph)
{
    check[x][y] = true;

    int next_x;
    int next_y;
    for(int i = 0; i < 4; i++)
    {
        next_x = x + x_pos[i];
        next_y = y + y_pos[i];

        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
            continue;

        if(check[next_x][next_y] == true)
            continue;
        
    	if (str[next_x][next_y] != alph)
    		continue;

        DFS(next_x, next_y, alph);
    }
}

int main()
{
    cin >> n;
    str.resize(n);

    vector<int> normal;
    vector<int> abnormal;

    for (int i = 0; i < n; i++)
    	cin >> str[i];

    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < n; j++)
	    {
            if (check[i][j] == false)
            {
                DFS(i, j, str[i][j]);

                normal.push_back(0);
            }
	    }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (str[i][j] == 'G')
                str[i][j] = 'R';

            check[i][j] = false;
        }
        //str[i].replace(str[i].begin(), str[i].end(), 'G', 'R');
        //memset(check[i], false, sizeof(check[i]));
    }

    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < n; j++)
	    {
		    if(check[i][j] == false)
		    {
                DFS(i, j, str[i][j]);

                abnormal.push_back(0);
		    }
	    }
    }

    cout << normal.size() << ' ' << abnormal.size();

    return 0;
}