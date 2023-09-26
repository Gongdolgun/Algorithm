#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
string str;

void F(int N, int X)
{
	if (N == 0)
		return;

	F(N / X, X);

	str = str + (char)((N % X) + 48);
}

bool isPrime(long long num) {
	if (num < 2) return false;

	for (int i = 2; i <= sqrt(num); ++i) {
		if (num % i == 0) return false;
	}
	return true;

}

int solution(int n, int k) {
    int answer = 0;

	F(n, k);
	string stmp = "";

	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] != '0')
		{
			stmp += str[i];

			if(i != str.length() - 1)
			continue;
		}

		if(stmp.empty())
			continue;

		if (isPrime(stoll(stmp)))
			answer++;

		stmp.clear();
	}

	cout << answer;

    return answer;
}

int main()
{
	int n, k;
	cin >> n >> k;

	solution(n, k);
}