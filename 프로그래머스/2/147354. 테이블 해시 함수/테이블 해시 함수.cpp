#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <bitset>
#include <thread>
#include <mutex>
#include <cstring>
#include <numeric>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

int cmpnum;

bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    if (v1[cmpnum] == v2[cmpnum])
        return v1[0] > v2[0];

    return v1[cmpnum] < v2[cmpnum];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    cmpnum = col - 1;

    sort(data.begin(), data.end(), cmp);

    for(int i = row_begin - 1; i < row_end; i++)
    {
        int num = 0;
        for(int j = 0; j < data[i].size(); j++)
        {
            num += data[i][j] % (i + 1);
        }

        answer ^= num;
    }

    return answer;
}