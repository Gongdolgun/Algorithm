#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while(n != 0)
    {
        int y = n % 2;
        n = n / 2;

        if(y != 0)
        {
            ans++;
        }
    }

    return ans;
}