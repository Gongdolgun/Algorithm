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
#include <cstring>
#include <numeric>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

char transform(int n)
{
	switch (n)
	{
	case 1:
        return '1';

	case 2:
        return '2';

	case 0:
        return '4';
	}
}

string solution(int n) {
    string answer = "";

    int a = n;

    while(1)
    {
        int b = a % 3;
        if (a == 0 && b == 0)
            break;

        if (b == 0)
            a--;

        a /= 3;

        answer += transform(b);
    }

    reverse(answer.begin(), answer.end());

    return answer;
}