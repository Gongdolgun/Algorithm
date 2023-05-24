#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    vector<int> vec;

    for (int i = 0; i < a.size(); i++)
        vec.push_back(a[i] * b[i]);

    for (auto V : vec)
        answer += V;

    return answer;
}