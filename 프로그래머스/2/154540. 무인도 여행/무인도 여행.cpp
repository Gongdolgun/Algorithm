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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    
    int SizeX = maps[0].size();
    int SizeY = maps.size();
    vector<vector<bool>> Visit(SizeY, vector<bool>(SizeX, 0));
    
    queue<pair<int, int>> qPair;
    
    for(int i = 0; i < SizeY; ++i)
    {
        for(int j = 0; j < SizeX; ++j)
        {
            if(maps[i][j] == 'X' || Visit[i][j] == true)
                continue;
            
            qPair.push({i, j});
            
            Visit[i][j] = true;
            int AddRange = 0;
            
            AddRange += maps[i][j] - '0';
            
            while(!qPair.empty())
            {
                pair<int, int> Cur = qPair.front();
                
                qPair.pop();
                
                // 방향 탐색
                for(int Dir = 0; Dir < 4; ++Dir)
                {
                    // 다음 탐색 위치
                    int NextX = Cur.second + dx[Dir];
                    int NextY = Cur.first + dy[Dir];
                    
                    if(NextX < 0 || NextY < 0 || NextX >= SizeX || NextY >= SizeY)
                        continue;
                    
                    if(maps[NextY][NextX] == 'X' || Visit[NextY][NextX] == 1)
                        continue;
                    
                    qPair.push({NextY, NextX});
                    Visit[NextY][NextX] = true;
                    AddRange += maps[NextY][NextX] - '0';
                }
            }
            
            answer.push_back(AddRange);
        }
    }
    
    if(answer.size() == 0)
    {
        answer.push_back(-1);
        
        return answer;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}