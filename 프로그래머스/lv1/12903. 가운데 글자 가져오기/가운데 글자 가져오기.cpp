#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.size() / 2;


    if (s.size() % 2 == 0)
    {
        answer.push_back(s[size - 1]);
        answer.push_back(s[size]);
    }

    else
        answer.push_back(s[size]);

    return answer;
}