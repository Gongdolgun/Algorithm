#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int tmp = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(B[i] > A[tmp])
        {
            tmp++;
            answer++;
        }
    }
    
    return answer;
}