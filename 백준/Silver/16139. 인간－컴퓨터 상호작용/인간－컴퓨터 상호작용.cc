#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

string str;
int N;
vector<int> cnt;

void input()
{
    cin >> str;
    cin >> N;
}

void solution()
{
    // string 입력값
	// x ~ y 범위까지 특정 알파벳이 몇번 들어가있는지 확인

    char alphabet;
    int min;
    int max;
    int temp = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> alphabet >> min >> max;

        for(int j = min; j <= max; j++)
            if (str[j] == alphabet)
                temp++;

        cnt.push_back(temp);
        temp = 0;
    }

    for(auto& Vec : cnt)
        cout << Vec << '\n';
}

void solve ()
{
    input();
    solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}