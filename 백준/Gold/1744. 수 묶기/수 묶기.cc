#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1e9

using namespace std;
vector<int> vec;

int main()
{
    FASTIO

    int n;
    cin >> n;
    int answer = 0;
    vector<int> Pos;
    vector<int> Neg;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        tmp > 0 ? Pos.push_back(tmp) : Neg.push_back(tmp);
    }

    sort(Pos.begin(), Pos.end(), greater<>());
    sort(Neg.begin(), Neg.end());

    // 양수 벡터에 1이 있다면 더하는게 더 크다 ex) (1, 2) 1 * 2 < 1 + 2
    // 2이상 부터는 곱하는게 더 크다. ex) (2, 3) 2 * 3 > 2 + 3

    if (Pos.size() % 2 == 1)
    {
        answer += Pos[Pos.size() - 1];
        Pos.erase(Pos.begin() + (Pos.size() - 1));
    }

    for(int i = 0; i < Pos.size(); i+=2)
    {
        if (Pos[i + 1] == 1)
            answer += Pos[i] + Pos[i + 1];

        else
            answer += Pos[i] * Pos[i + 1];
    }

    // 음수 벡터는 무조건 두 수가 곱해지는게 좋다.
    // 사이즈가 홀수라면 마지막 수는 더해져야 한다.

    if (Neg.size() % 2 == 1)
    {
        answer += Neg[Neg.size() - 1];
        Neg.erase(Neg.begin() + Neg.size() - 1);
    }

    for(int i = 0; i < Neg.size(); i+=2)
        answer += Neg[i] * Neg[i + 1];

    cout << answer;

    return 0;
}