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

int answer{ 100 };
 
void dfs(string begin, string target, vector<string> words, vector<bool>& useCheck, int cnt = 0) {
    for (int i = 0; i < words.size(); i++) {
        int count{ 0 };
        for (int j = 0; j < words[i].length(); j++)
            if (!useCheck[i] && begin[j] != words[i][j])    count++;
        if (count == 1) {
            if (target == words[i] && answer > cnt + 1) {
                answer = cnt + 1;
                return;
            }
            useCheck[i] = true;
            dfs(words[i], target, words, useCheck, cnt + 1);
            useCheck[i] = false;
        }
    }
}
 
int solution(string begin, string target, vector<string> words) {
    vector<bool> useCheck(words.size(), false);
    dfs(begin, target, words, useCheck);
    if (answer == 100)   return 0;
    return answer;
}