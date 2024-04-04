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
#define INF 987654321
#define ll long long

using namespace std;

ll solution(vector<int> vec)
{
    priority_queue<long long, vector<ll>, greater<>> pq;
    ll answer = 0;

    for(auto& V : vec)
    {
        pq.push(V);
    }

    while(!pq.empty())
    {
        ll first = pq.top();
        pq.pop();

        ll second = pq.top();
        pq.pop();

        ll sum = first + second;
        answer += sum;

        if(!pq.empty())
			pq.push(sum);
    }

    return answer;
}

int main()
{
    FASTIO

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> vec(m);

        for (int j = 0; j < m; j++)
            cin >> vec[j];

        cout << solution(vec) << '\n';
    }

    return 0;
}
