#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int arr[101][101];

void init(int row, int column)
{
	int tmp = 1;

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= column; j++)
		{
			arr[i][j] = tmp;
			tmp++;
		}
	}
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
	
	init(rows, columns);

	for(int i = 0; i < queries.size(); i++)
	{
		int start_row = queries[i][0];
		int start_column = queries[i][1];
		int end_row = queries[i][2];
		int end_column = queries[i][3];
		int minNum = 987654321;

		int tmp = arr[start_row][end_column];
		int tmp2 = 0;
		for (int j = end_column; j > start_column; j--)
		{
			arr[start_row][j] = arr[start_row][j - 1];
			minNum = min(minNum, arr[start_row][j]);
		}

		tmp2 = arr[end_row][end_column];
		for (int j = end_row; j > start_row + 1; j--)
		{
			arr[j][end_column] = arr[j - 1][end_column];
			minNum = min(minNum, arr[j][end_column]);
		}
		arr[start_row + 1][end_column] = tmp;
		minNum = min(minNum, arr[start_row + 1][end_column]);

		
		tmp = arr[end_row][start_column];
		for (int j = start_column; j < end_column - 1; j++)
		{
			arr[end_row][j] = arr[end_row][j + 1];
			minNum = min(minNum, arr[end_row][j]);
		}
		arr[end_row][end_column - 1] = tmp2;
		minNum = min(minNum, arr[end_row][end_column - 1]);

		
		for (int j = start_row; j < end_row - 1; j++)
		{
			arr[j][start_column] = arr[j + 1][start_column];
			minNum = min(minNum, arr[j][start_column]);
		}
		arr[end_row - 1][start_column] = tmp;
		minNum = min(minNum, arr[end_row - 1][start_column]);

		answer.push_back(minNum);
	}

    return answer;
}

int main()
{
	int row, column, size;
	cin >> row >> column >> size;

	vector<vector<int>> queries(size, vector<int>(4));
	for(int i = 0; i < size; i++)
		for (int j = 0; j < 4; j++)
			cin >> queries[i][j];

	solution(row, column, queries);

}