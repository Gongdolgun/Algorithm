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

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int, int>> yellows;

    for(int i = 1; i * i <= yellow; i++)
    {
        if (yellow % i == 0)
            yellows.push_back({ i, yellow / i });
    }

    for(int i = 0; i < yellows.size(); i++)
    {
	    if((yellows[i].first * 2) + (yellows[i].second * 2) + 4 == brown)
	    {
            answer.push_back(yellows[i].second + 2);
            answer.push_back(yellows[i].first + 2);
            break;
	    }
    }

    return answer;
}