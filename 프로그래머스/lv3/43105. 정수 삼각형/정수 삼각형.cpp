#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int vec[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vec[0][0] = triangle[0][0];
    int n = triangle.size();

    for(int i = 1; i < n; i++)
    {
	    for(int j = 0; j <= i; j++)
	    {
		    if(j == 0)
		    {
				vec[i][j] = vec[i - 1][j] + triangle[i][j];
		    }

			else if(j == i)
			{
				vec[i][j] = vec[i - 1][j - 1] + triangle[i][j];
			}

			else
			{
				vec[i][j] = max(vec[i - 1][j - 1], vec[i - 1][j]) + triangle[i][j];
			}
	    }
    }

	for (int k = 0; k < n; k++)
	{
		answer = max(answer, vec[n - 1][k]);
	}

	cout << answer;

    return answer;
}