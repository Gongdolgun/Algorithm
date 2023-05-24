#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    int count = 0;
    vector<int> vec;

    for(int i = left; i <= right; i++)
    {
	    for(int j = 1; j <= i; j++)
	    {
            if (i % j == 0)
                count++;
	    }

        count % 2 == 0 ? vec.push_back(i) : vec.push_back(i * -1);
        count = 0;
    }

    for (auto Vec : vec)
        answer += Vec;

    return answer;
}