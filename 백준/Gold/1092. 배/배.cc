#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int N, M, minute;
vector<int> Crain;
vector<int> Weight;
vector<bool> check;

void input()
{
    cin >> N;
    Crain.resize(N);

    for(int i = 0; i < Crain.size(); i++)
        cin >> Crain[i];

    cin >> M;
    Weight.resize(M);
    check.resize(M);

    for(int j = 0; j < Weight.size(); j++)
        cin >> Weight[j];
}

void solution()
{
    sort(Crain.begin(), Crain.end(), greater<>());
    sort(Weight.begin(), Weight.end(), greater<>());

    if (Crain[0] < Weight[0])
    {
        cout << -1;
        return;
    }

    while(1)
    {
        if (Weight.empty())
            break;

        for(int i = 0; i < Crain.size(); i++)
        {
	        for(int j = 0; j < Weight.size(); j++)
	        {
                if (Crain[i] >= Weight[j])
                {
                    Weight.erase(Weight.begin() + j);
                    break;
                }
	        }
        }

        minute++;
    }

    cout << minute;
}

int main()
{
    input();
    solution();

    return 0;
}