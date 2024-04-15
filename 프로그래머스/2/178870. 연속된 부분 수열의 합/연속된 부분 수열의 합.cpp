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

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    answer[1] = INF;

    int left = 0, right = 0;
    vector<pair<int, int>> result;
    int sum = sequence[0];

    while(1)
    {
        if (left > right)
            break;

        if (right >= sequence.size())
            break;

        if(sum < k)
        {
            right++;
            sum += sequence[right];
        }

        else if(sum > k)
        {
            sum -= sequence[left];
            left++;
        }

        else
        {
            if (abs(answer[1] - answer[0]) > abs(right - left))
            {
                answer[0] = left;
                answer[1] = right;
            }
            sum -= sequence[left];
            left++;
        }
    }

    cout << answer[0] << ' ' << answer[1];

    return answer;
}

int main()
{
    FASTIO
	solution({ 1, 2, 3, 4, 5 }, 7);

    return 0;
}