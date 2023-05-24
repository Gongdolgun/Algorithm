#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    answer = 0;

    for (int i = 0; i < numbers.size(); i++)
        answer += numbers[i];

    answer = 45 - answer;

    return answer;
}