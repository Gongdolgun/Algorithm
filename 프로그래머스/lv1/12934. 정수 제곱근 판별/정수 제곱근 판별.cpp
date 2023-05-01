#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);

    if (answer * answer == n)
        answer = ((long long)sqrt(n) + 1) * ((long long)sqrt(n) + 1);

    else
        answer = -1;

    return answer;
}

int main()
{
    cout << solution(144);

    return 0;
}
