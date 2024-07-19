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

vector<vector<int>> m;

void dfs(int x, int y, int n, vector<int> &answer){
    int sum=0;
    
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            sum+=m[i][j];
    
    if(sum==0){
        answer[0]++;
        return;
    }
    
    else if(sum==n*n){
        answer[1]++;
        return;
    }
    
    dfs(x, y, n/2, answer);
    dfs(x, y+n/2, n/2, answer);
    dfs(x+n/2, y, n/2, answer);
    dfs(x+n/2, y+n/2, n/2, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    m=arr;
    
    dfs(0, 0, arr.size(), answer);
    
    return answer;
}