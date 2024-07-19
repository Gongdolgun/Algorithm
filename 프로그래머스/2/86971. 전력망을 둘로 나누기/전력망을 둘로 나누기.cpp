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

int counter = 0;
bool visit[101];

void dfs(vector<vector<int>>& v, int num) {
    
    counter++;
    visit[num] = true;
    
    for(int i = 0; i < v[num].size(); i++) {
        
        if(!visit[v[num][i]]) {
            
            dfs(v, v[num][i]);
        }
        
    }
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for(int i = 0; i < n - 1; i++) {
        
        vector<vector<int>> v(n + 1, vector<int>());
        memset(visit, 0, sizeof(visit));
        counter = 0;
        
        for(int j = 0; j < n - 1; j++) {
            
            if(i == j)
                continue;
            else {
                // 양방향 연결
                v[wires[j][0]].push_back(wires[j][1]);
                v[wires[j][1]].push_back(wires[j][0]);
            }
            
        }
        
        
        dfs(v, 1);
        if(abs(counter - abs(n - counter)) <= answer)
            answer = abs(counter - abs(n - counter));
        
    }
    
    
    return answer;
}