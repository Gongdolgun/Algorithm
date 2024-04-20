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
#include <unordered_map>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define ll long long

using namespace std;

pair<int, int> check(int a, int b)
{
    if (a % 2 == 0)
        a = a / 2;

    else
        a = a / 2 + 1;

    if (b % 2 == 0)
        b = b / 2;

    else
        b = b / 2 + 1;

    return make_pair(a, b);
}

int solution(int n, int a, int b)
{
    int answer = 1;

    pair<int, int> result;
    while(1)
    {
        result = check(a, b);
        a = result.first;
        b = result.second;

        if (a == b)
            break;

        else
            answer++;
    }
    
    return answer;
}