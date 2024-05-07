#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <thread>
#include <mutex>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for(int i = 0; i < arr1.size(); i++)
    {
        vector<int> result;

	    for(int j = 0; j < arr2[0].size();j++)
	    {
		    int sum = 0;
		    for(int k = 0; k < arr1[0].size(); k++)
		    {
		        sum += arr1[i][k] * arr2[k][j];
		    }
		    result.push_back(sum);
	    }
        answer.push_back(result);
    }

    return answer;
}