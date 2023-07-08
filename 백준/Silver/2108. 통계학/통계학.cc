#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> vec;
int N;

void input()
{
    cin >> N;
    int temp;

	for(int i = 1; i <= N; i++)
	{
        cin >> temp;
		vec.push_back(temp);
	}
}

void Choibin(vector<int> vec)
{
	map<int, int> Map;

    for(auto& Vec : vec)
        Map.insert(make_pair(Vec, 0));

    for(auto& Vec: vec)
    {
        auto Find = Map.find(Vec);

        if(Find != Map.end())
        {
            Find->second++;
        }
    }

    int Max_num = Map.begin()->second;

    for (auto iter = Map.begin(); iter != Map.end(); iter++)
    {
        Max_num = max(Max_num, iter->second);
    }

    vector<int> choibin;
    for (auto iter = Map.begin(); iter != Map.end(); iter++)
    {
        if (iter->second == Max_num)
            choibin.push_back(iter->first);
    }
    sort(choibin.begin(), choibin.end());

    if (choibin.size() == 1)
        cout << choibin[0] << '\n';
    
    else
        cout << choibin[1] << '\n';
}

void solution()
{
    //산술평균: N개의 수들의 합을 N으로 나눈 값
    //중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
    //최빈값 : N개의 수들 중 가장 많이 나타나는 값
    //범위 : N개의 수들 중 최댓값과 최솟값의 차이

    double Average_San;
    int Middle;
    //int Choi;
    int Bum;

    double sum = 0;

    for(int i = 0; i < N; i++)
        sum += vec[i];

    if(sum >= 0)
		Average_San = floor((sum / N) + 0.5f);

    else
        Average_San = floor(abs(sum / N) + 0.5f) * -1;

    if (Average_San == -0)
        Average_San = 0;

    cout << Average_San << '\n';        // 산술평균

    sort(vec.begin(), vec.end());

    Middle = vec[N / 2];
	cout << Middle << '\n';             // 중앙값

    Choibin(vec);

    Bum = vec[N-1] - vec[0];
    cout << Bum << '\n';                // 범위 
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