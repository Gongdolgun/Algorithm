#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for(int i = 0; i < n; i++)
        i % 2 == 0 ? answer += "수" : answer += "박";     // string은 무조건 +가 이득임

    return answer;
}

int main()
{
    int n = 3;
    string vec;

    vec = solution(n);

    for(auto Vec : vec)
    {
        cout << Vec;
    }

    return 0;
}