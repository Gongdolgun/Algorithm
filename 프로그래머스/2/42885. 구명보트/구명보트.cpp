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

int solution(vector<int> people, int limit) {
    int answer = 0;
    int weight = 0;
    sort(people.begin(), people.end());

    int i = 0, j = people.size() - 1;

    while(i <= j)
    {
        if (people[i] + people[j] <= limit)
            i++;

    	j--;
        answer++;
    }

    cout << answer;

    return answer;
}

int main()
{
    FASTIO

	vector<int> people = {70, 50, 50, 80};
    int limit;
    cin >> limit;

    solution(people, limit);

    return 0;
}