#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
	long long n;

	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}

	return a;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long a, b;
	
	cin >> a >> b;

	cout << lcm(a, b);

	return 0;
}