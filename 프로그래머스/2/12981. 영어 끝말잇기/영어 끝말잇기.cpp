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

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    map<string, int> m;

    int player = 1, round = 1;
    m[words[0]] = 1;

    for(int i = 1; i < words.size(); i++)
    {
        player = (i % n) + 1;
        round = (i / n) + 1;

        if(words[i-1][words[i-1].size()-1] != words[i][0])
        {
            answer[0] = player;
            answer[1] = round;

            break;
        }

        if(m[words[i]] != 0)
        {
            answer[0] = player;
            answer[1] = round;

            break;
        }

        m[words[i]] = 1;
    }

    return answer;
}