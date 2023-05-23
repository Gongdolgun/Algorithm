#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;

    int num = 0;

    string str = std::to_string(x);

    for(int i = 0; i < str.length(); i++)
    {
        num += str[i] - '0';
    }

    if (x % num == 0)
        answer = true;

    else
        answer = false;

    return answer;
}