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

vector<int> v;
vector<bool> check;

int cycle(int n)
{
    int tmp = n;
    vector<int> box;
	while(1)
	{
        if (check[tmp] == true)
            break;

        check[tmp] = true;
        tmp = v[tmp];
        box.push_back(v[tmp]);
	}

    return box.size();
}

int solution(vector<int> cards) {
    int answer = 0;

    v.resize(cards.size() + 1);
    check.resize(cards.size() + 1);
    vector<int> boxes_size;

    for (int i = 1; i <= cards.size(); i++)
        v[i] = cards[i - 1];

    for(int i = 1; i <= cards.size(); i++)
    {
        if (check[i] == false)
            boxes_size.push_back(cycle(i));
    }

    sort(boxes_size.begin(), boxes_size.end(), greater<>());
    answer = boxes_size[0] * boxes_size[1];

    return answer;
}