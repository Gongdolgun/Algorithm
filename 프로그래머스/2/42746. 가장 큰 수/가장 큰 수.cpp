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

bool cmp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    
    for (auto num : numbers)
        tmp.push_back(to_string(num));

    sort(tmp.begin(), tmp.end(), cmp);

    if (tmp.at(0) == "0")        
		    return "0";

    for (auto num : tmp)
        answer += num;
        
    return answer;
}