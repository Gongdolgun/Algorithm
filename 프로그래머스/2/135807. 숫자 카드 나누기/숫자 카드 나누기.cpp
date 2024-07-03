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

vector<vector<pair<int, int>>> coo (51);
vector<int> cost(51, INF);

int gcd(const vector<int>& arr)
{
    int num1 = arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        int num2 = arr[i];

        while(1)
        {
            int num3 = num2 % num1;
            if (num3 == 0)
                break;

            num2 = num1;
            num1 = num3;
        }
    }

    return num1;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    int num1 = gcd(arrayA);
    int num2 = gcd(arrayB);

    answer = max(num1, num2);

    if(answer == num1)
    {
	    for(auto& B : arrayB)
            if (B % answer == 0) return 0;
    }

    else
    {
		for(auto& A : arrayA)
		{
            if (A % answer == 0) return 0;
		}
    }

    return answer;
}