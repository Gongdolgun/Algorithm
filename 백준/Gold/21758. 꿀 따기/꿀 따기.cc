#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int answer = 0;
    int n;
    cin >> n;

    vector<int> honey(n);
    vector<int> sum(n);

    int tmp = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> honey[i];
        tmp += honey[i];
        sum[i] = tmp;
    }

    // 1. 벌 꿀 벌
    // 2. 벌 벌 꿀
    // 3. 꿀 벌 벌

    for(int i = 1; i < n - 1; i++)
    {
        answer = max(answer, (sum[i] - honey[0]) + (sum[n - 2] - sum[i - 1]));
    }

    for(int i = 1; i < n; i++)
    {
        answer = max(answer, (sum[n - 1] - honey[0] - honey[i]) + (sum[n - 1] - sum[i]));
    }

    for(int i = n - 2; i > 0; i--)
    {
        answer = max(answer, (sum[n - 2] - honey[i]) + (sum[i - 1]));
    }

    cout << answer;

    return 0;
}