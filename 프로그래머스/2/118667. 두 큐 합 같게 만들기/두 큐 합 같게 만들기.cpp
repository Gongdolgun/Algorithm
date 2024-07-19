#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <thread>
#include <mutex>
#include <cstring>
#include <numeric>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    
    int answer_limit = queue1.size() * 2 + 1;
    long sum1 = 0, sum2 = 0;
    queue<int> q1, q2;
    for(int i = 0; i < queue1.size(); ++i) {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    long long half = (sum1 + sum2) / 2;
    
    int answer = 0;
    while(!q1.empty() && !q2.empty())
    {
        if(sum1 == half)
            return answer;
        
        if(answer > answer_limit)
            return -1;
        
        int front1 = q1.front();
        int front2 = q2.front();
        
        // 좌측 큐가 더 크다면?
        if(sum1 > half)
        {
            q1.pop();
            q2.push(front1);
            sum1 -= front1;
            sum2 += front1;
        }
        else
        {
            q2.pop();
            q1.push(front2);
            sum1 += front2;
            sum2 -= front2;
        }
        
        ++answer;
    }
    
    return -1;
}