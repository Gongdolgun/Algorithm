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

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;

    for(int i = 0; i < operations.size(); i++)
    {
	    if(operations[i][0] == 'I')     //Insert
	    {
            string str = operations[i].substr(2, operations[i].size() - 2);
            auto it = lower_bound(dq.begin(), dq.end(), stoi(str));

            dq.insert(it, stoi(str));
	    }

	    else     //Delete
	    {
            if (dq.empty())
                continue;

            string str = operations[i].substr(2, operations[i].size() - 2);
            if (str == "-1")
                dq.pop_front();

            else
                dq.pop_back();
	    }
    }

    if (dq.empty())
        answer = { 0, 0 };

    else
        answer = { dq.back(), dq.front() };

    return answer;
}