#include<iostream>
#include<vector>
#include <algorithm>
#include<string>
#include<queue>

using namespace std;

int N;
vector<int> dist;
vector<int> price;

void input(){
	cin >> N;

	dist.resize(N - 1);
	price.resize(N);

	for (int i = 0; i < N - 1; i++)
		cin >> dist[i];

	for (int j = 0; j < N; j++)
		cin >> price[j];
}

void solution(){
	int minPrice = price[0];
	int distSum = 0;
	int answer = 0;

	for(int r = 0; r < N-1; r++)
	{
		minPrice = min(minPrice, price[r]);
	}

	for(int i = 0; i < N-1; i++)
	{
		if(price[i] == minPrice)
		{
			for(int j = i; j < N-1; j++)
			{
				distSum += dist[j];
			}

			answer += distSum * price[i];
			break;
		}
		answer += price[i] * dist[i];
	}

	cout << answer;
}

void solve(){
	input();
	solution();
}

int main() {

	solve();

	return 0;
}